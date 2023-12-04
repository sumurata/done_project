/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:05:10 by sumurata          #+#    #+#             */
/*   Updated: 2023/10/25 21:37:44 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	totalsize;
	void	*ptr;

	totalsize = 0;
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (size < (SIZE_MAX / count))
	{
		totalsize = count * size;
		ptr = malloc(totalsize);
		if (ptr == NULL)
			return (NULL);
		ft_memset(ptr, 0, totalsize);
	}
	else
		return (NULL);
	return (ptr);
}
