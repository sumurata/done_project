/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:20:01 by sumurata          #+#    #+#             */
/*   Updated: 2023/10/25 21:39:22 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memmove_helper(void *buf1, const void *buf2, size_t n)
{
	unsigned char		*b1;
	const unsigned char	*b2;
	size_t				i;

	b1 = (unsigned char *)buf1;
	b2 = (const unsigned char *)buf2;
	if (b1 > b2)
	{
		i = n;
		if (n == 0)
			return (buf1);
		while (i--)
			b1[i] = b2[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			b1[i] = b2[i];
			i++;
		}
	}
	return (buf1);
}

void	*ft_memmove(void *buf1, const void *buf2, size_t n)
{
	unsigned char		*b1;
	const unsigned char	*b2;

	b1 = (unsigned char *)buf1;
	b2 = (const unsigned char *)buf2;
	if (b1 == NULL && b2 == NULL)
		return (NULL);
	memmove_helper(buf1, buf2, n);
	return (buf1);
}
