/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:10:35 by sumurata          #+#    #+#             */
/*   Updated: 2023/11/05 18:41:07 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*substr;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	while (s[j] != '\0')
		j++;
	if (start >= j)
		return ((char *)ft_calloc(1, 1));
	if (j > len)
		j = len;
	substr = (char *)malloc(j + 1);
	if (substr == NULL)
		return (NULL);
	while (i < j)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
