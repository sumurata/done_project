/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:03:50 by sumurata          #+#    #+#             */
/*   Updated: 2023/10/25 16:12:33 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
		{
			return (1);
		}
		set++;
	}
	return (0);
}

static size_t	strrim_helper(char const *s1)
{
	size_t	s1_len;

	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	return (s1_len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed_str;
	size_t	i;
	size_t	j;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = strrim_helper(s1);
	while (start < end && is_in_set(s1[start], set))
		start++;
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	trimmed_str = (char *)malloc(end - start + 1);
	if (trimmed_str == NULL)
		return (NULL);
	i = 0;
	j = start;
	while (j < end)
		trimmed_str[i++] = s1[j++];
	trimmed_str[i] = '\0';
	return (trimmed_str);
}
