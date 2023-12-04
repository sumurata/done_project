/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:49:39 by sumurata          #+#    #+#             */
/*   Updated: 2023/11/05 11:00:03 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_len;
	char	*result;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	s_len = 0;
	while (s[s_len])
		s_len++;
	result = (char *)malloc(s_len + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[s_len] = '\0';
	return (result);
}
