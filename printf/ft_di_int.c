/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:41:43 by sumurata          #+#    #+#             */
/*   Updated: 2023/11/29 15:09:05 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_di_int(int i)
{
	char	*str;
	int		n;

	str = ft_itoa(i);
	n = ft_putcount(str);
	free(str);
	return (n);
}
