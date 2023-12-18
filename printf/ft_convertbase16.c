/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertbase16.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:30:43 by sumurata          #+#    #+#             */
/*   Updated: 2023/12/13 18:18:17 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*casezero(char *dest)
{
	dest = (char *)ft_calloc(2, sizeof(char));
	dest[0] = '0';
	return (dest);
}

static int	counti(unsigned long long num, int i)
{
	while (num > 0)
	{
		num = num / 16;
		i++;
	}
	return (i);
}

char	*ft_convertbase16(unsigned long long num)
{
	int					i;
	int					j;
	char				*base;
	char				*dest;
	unsigned long long	tmp;

	base = "0123456789ABCDEF";
	dest = NULL;
	tmp = num;
	i = 0;
	if (num == 0)
		return (casezero(dest));
	i = counti(num, i);
	dest = (char *)ft_calloc(i + 1, sizeof(char));
	dest[i] = '\0';
	while (i > 0)
	{
		i--;
		j = tmp % 16;
		tmp = tmp / 16;
		dest[i] = base[j];
	}
	return (dest);
}
