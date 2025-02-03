/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:28:33 by tcybak            #+#    #+#             */
/*   Updated: 2024/10/17 11:28:37 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*str;
	t_list	*bef;

	if (lst == NULL || del == NULL)
		return ;
	str = *lst;
	if (str == NULL)
		*lst = NULL;
	while (str)
	{
		bef = str->next;
		del(str->content);
		free(str);
		str = bef;
	}
	*lst = NULL;
}
