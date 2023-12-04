/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:50:08 by sumurata          #+#    #+#             */
/*   Updated: 2023/10/21 19:51:47 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (new != NULL)
	{
		temp = *lst;
		if (temp == NULL)
			*lst = new;
		else
		{
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new;
		}
	}
}
