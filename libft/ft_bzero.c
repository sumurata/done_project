/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:16:42 by sumurata          #+#    #+#             */
/*   Updated: 2023/10/25 21:37:02 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *buf, size_t len)
{
	unsigned char	*b;
	size_t			i;

	b = buf;
	i = 0;
	while (i < len)
	{
		b[i] = '\0';
		i++;
	}
}
