/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:40:20 by sumurata          #+#    #+#             */
/*   Updated: 2023/10/25 21:39:29 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int value, size_t len)
{
	unsigned char	*b;
	size_t			i;

	b = buf;
	i = 0;
	while (i < len)
	{
		b[i] = (unsigned char)value;
		i++;
	}
	return (buf);
}
