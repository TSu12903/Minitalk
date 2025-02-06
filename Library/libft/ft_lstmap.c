/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:48:23 by tcybak            #+#    #+#             */
/*   Updated: 2024/10/17 13:48:26 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*str;
	t_list	*new;
	void	*content;

	if (f == NULL || lst == NULL || del == NULL)
		return (NULL);
	new = NULL;
	while (lst != NULL)
	{
		str = NULL;
		content = f(lst->content);
		if (content != NULL)
			str = ft_lstnew(content);
		if (str == NULL)
		{
			del(content);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, str);
		lst = lst->next;
	}
	return (new);
}
