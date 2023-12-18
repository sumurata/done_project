/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_voidp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:37:48 by sumurata          #+#    #+#             */
/*   Updated: 2023/12/13 18:27:24 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p_voidp(unsigned long long point)
{
	char	*p;
	int		n;

	p = ft_tolower(ft_convertbase16(point));
	n = ft_putcount("0x");
	n += ft_putcount(p);
	free(p);
	return (n);
}
