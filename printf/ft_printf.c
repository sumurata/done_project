/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:19:13 by sumurata          #+#    #+#             */
/*   Updated: 2023/12/11 12:50:21 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	va_list		args;
	const char	*tmp;
	int			num;

	num = 0;
	tmp = ft_strdup(input);
	if (!tmp)
		return (0);
	va_start(args, input);
	num = ft_output(tmp, args);
	va_end(args);
	free((char *)tmp);
	return (num);
}
