/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:50:03 by sumurata          #+#    #+#             */
/*   Updated: 2023/10/25 21:38:56 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int ch, size_t n)
{
	const unsigned char	*b;
	unsigned char		uch;
	size_t				i;

	b = (const unsigned char *)buf;
	uch = (unsigned char)ch;
	i = 0;
	while (i < n)
	{
		if (b[i] == uch)
			return ((void *)&b[i]);
		i++;
	}
	return (NULL);
}
