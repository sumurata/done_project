/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlx_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:12:15 by sumurata          #+#    #+#             */
/*   Updated: 2023/12/11 14:28:23 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_xlx_ui(unsigned int i, int f)
{
	char	*num16;
	int		n;

	if (!i)
		i = 0;
	num16 = ft_convertbase16((unsigned long long)i);
	if (f == 1)
		num16 = ft_tolower(num16);
	n = ft_putcount(num16);
	free(num16);
	return (n);
}
