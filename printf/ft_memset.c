/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:14:09 by sumurata          #+#    #+#             */
/*   Updated: 2023/12/10 18:37:56 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *b, int value, size_t len)
{
	unsigned char	*buf;
	size_t			i;

	buf = b;
	i = 0;
	while (i < len)
	{
		buf[i] = (unsigned char)value;
		i++;
	}
	return (buf);
}
