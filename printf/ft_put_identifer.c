/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_identifer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:37:33 by sumurata          #+#    #+#             */
/*   Updated: 2023/12/13 20:05:26 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_identifer(int c, va_list args)
{
	int	n;

	n = 0;
	if (c == 'c')
		n = ft_c_char(va_arg(args, int));
	else if (c == 's')
		n = ft_s_char(va_arg(args, char *));
	else if (c == 'p')
		n = ft_p_voidp((unsigned long long)va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		n = ft_di_int(va_arg(args, int));
	else if (c == 'u')
		n = ft_u_ull((size_t)va_arg(args, unsigned int));
	else if (c == 'x')
		n = ft_xlx_ui(va_arg(args, unsigned int), 1);
	else if (c == 'X')
		n = ft_xlx_ui(va_arg(args, unsigned int), 2);
	else if (c == '%')
		n = ft_putcount("%");
	return (n);
}
