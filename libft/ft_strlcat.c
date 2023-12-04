/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:26:55 by sumurata          #+#    #+#             */
/*   Updated: 2023/10/25 21:40:36 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destsize;
	size_t	srcsize;
	size_t	i;

	destsize = 0;
	srcsize = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dest[destsize] != '\0' && destsize < size)
		destsize++;
	while (src[srcsize] != '\0')
		srcsize++;
	if (size <= destsize)
		return (size + srcsize);
	i = 0;
	while (i < srcsize && destsize + i < size - 1)
	{
		dest[destsize + i] = src[i];
		i++;
	}
	dest[destsize + i] = '\0';
	return (destsize + srcsize);
}
