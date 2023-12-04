/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:20:31 by sumurata          #+#    #+#             */
/*   Updated: 2023/10/25 21:38:27 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	digits_count(long n)
{
	size_t	num_digits;

	num_digits = 0;
	if (n == 0)
		return (1);
	if (n == INT_MIN)
		return (11);
	while (n != 0)
	{
		n /= 10;
		num_digits++;
	}
	return (num_digits);
}

static char	*int_to_str(long n, size_t index, size_t sign, char *str)
{
	while (index != 0)
	{
		if (sign == 1 && index == 1)
			break ;
		str[index - 1] = '0' + (n % 10);
		n /= 10;
		index--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	sign;
	size_t	index;
	char	*str;
	long	tmp;

	tmp = (long)n;
	sign = 0;
	if (tmp < 0)
	{
		sign = 1;
		tmp = -tmp;
	}
	index = digits_count(tmp);
	str = (char *)malloc((index + sign + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (sign == 1)
	{
		str[0] = '-';
		str = int_to_str(tmp, index + 1, sign, str);
	}
	else
		str = int_to_str(tmp, index, sign, str);
	str[index + sign] = '\0';
	return (str);
}
