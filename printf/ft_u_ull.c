/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_ull.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:59:50 by sumurata          #+#    #+#             */
/*   Updated: 2023/12/13 15:33:15 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	tencount(unsigned int n)
{
	char			str;
	unsigned int	tmp;
	size_t			t;

	tmp = n;
	t = 0;
	while (9 < tmp)
	{
		tmp = tmp / 10;
		t++;
	}
	if (9 < n)
		tencount(n / 10);
	str = '0' + n % 10;
	write(1, &str, 1);
	return (t + 1);
}

int	ft_u_ull(unsigned int u)
{
	int	n;

	n = 0;
	n = tencount(u);
	return (n);
}
