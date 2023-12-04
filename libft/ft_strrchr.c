/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:48:10 by sumurata          #+#    #+#             */
/*   Updated: 2023/11/06 12:48:10 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	uc;
	char			*ret;

	i = 0;
	uc = (unsigned char)c;
	ret = NULL;
	while (1)
	{
		if (uc == s[i])
			ret = (char *)&s[i];
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (ret);
}
