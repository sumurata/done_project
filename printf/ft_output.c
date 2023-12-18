/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:50:35 by sumurata          #+#    #+#             */
/*   Updated: 2023/12/13 20:18:22 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_output(const char *tmp, va_list args)
{
	size_t	i;
	size_t	put_length;
	int		ret;

	i = 0;
	put_length = 0;
	while (tmp[i])
	{
		if (tmp[i] == '%')
		{
			i++;
			ret = ft_put_identifer(tmp[i], args);
			if (ret == -1)
				return (ret);
			put_length += ret;
		}
		else
		{
			ft_putchar_fd(tmp[i], 1);
			put_length++;
		}
		i++;
	}
	return (put_length);
}
