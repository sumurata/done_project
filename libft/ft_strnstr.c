/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:04:49 by sumurata          #+#    #+#             */
/*   Updated: 2023/10/25 21:41:20 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *heystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	i = 0;
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)&heystack[i]);
	while (i < len && heystack[i] != '\0')
	{
		if (heystack[i] == needle[0] && i + needle_len <= len)
		{
			if (ft_strncmp(&heystack[i], needle, needle_len) == 0)
				return ((char *)&heystack[i]);
		}
		i++;
	}
	return (NULL);
}
