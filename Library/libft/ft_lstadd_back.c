/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:55:43 by tcybak            #+#    #+#             */
/*   Updated: 2024/10/17 09:55:46 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*str;

	if (!lst || !new)
		return ;
	str = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (str->next != NULL)
			str = str->next;
		str->next = new;
	}
}
