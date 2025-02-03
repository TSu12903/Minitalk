/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:28:41 by tcybak            #+#    #+#             */
/*   Updated: 2024/11/04 16:01:04 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_type2(const char *form, int *i, va_list ap)
{
	if (*form == 'u')
		ft_printu(va_arg(ap, unsigned int), i);
	if (*form == 'x')
		ft_printhex(va_arg(ap, unsigned int), "0123456789abcdef", i);
	if (*form == 'X')
		ft_printhex(va_arg(ap, unsigned int), "0123456789ABCDEF", i);
}

static int	check_type1(const char *form, int i, va_list ap)
{
	if (*form == 'c')
		i += ft_putchar((char)va_arg(ap, int));
	if (*form == 's')
		i += ft_putstr(va_arg(ap, char *));
	if (*form == 'd' || *form == 'i')
		i += ft_putnbr(va_arg(ap, int));
	if (*form == 'p')
		i += ft_printadd1(va_arg(ap, size_t));
	return (i);
}

int	ft_printf(const char *form, ...)
{
	int			i;
	va_list		ap;

	if (!form)
		return (-1);
	va_start(ap, form);
	i = 0;
	while (*form)
	{
		if (*form != '%')
			i += ft_putchar(*form);
		if (*form == '%')
		{
			form++;
			if (!*form)
				return (-1);
			i = check_type1(form, i, ap);
			check_type2(form, &i, ap);
			if (*form == '%')
				i += write(1, "%", 1);
		}
		form++;
	}
	va_end(ap);
	return (i);
}
