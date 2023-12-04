/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:08:09 by sumurata          #+#    #+#             */
/*   Updated: 2023/10/25 21:39:13 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *buf1, const void *buf2, size_t n)
{
	char		*b1;
	const char	*b2;
	size_t		i;

	b1 = buf1;
	b2 = buf2;
	i = 0;
	if (b1 == NULL && b2 == NULL)
		return (NULL);
	while (i < n)
	{
		b1[i] = b2[i];
		i++;
	}
	return (buf1);
}
