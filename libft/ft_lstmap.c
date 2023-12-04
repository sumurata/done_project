/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:17:34 by sumurata          #+#    #+#             */
/*   Updated: 2023/10/23 12:20:29 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*last_node;
	void	*content_copy;

	new_list = NULL;
	last_node = NULL;
	while (lst)
	{
		content_copy = f(lst->content);
		new_node = ft_lstnew(content_copy);
		if (!content_copy || !new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		if (!new_list)
			new_list = new_node;
		else
			last_node->next = new_node;
		last_node = new_node;
		lst = lst->next;
	}
	return (new_list);
}
