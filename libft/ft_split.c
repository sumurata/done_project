/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:06:53 by sumurata          #+#    #+#             */
/*   Updated: 2023/11/05 14:49:18 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;
	int		in_word;

	count = 0;
	i = 0;
	in_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (!in_word)
			{
				count++;
				in_word = 1;
			}
		}
		else
			in_word = 0;
		i++;
	}
	return (count);
}

static void	write_word(char *dest, char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
}

static void	*iffaild_free(char **split, size_t count)
{
	size_t	k;

	k = 0;
	while (count > k)
	{
		free(split[k]);
		k++;
	}
	return (NULL);
}

static char	**write_split(char **split, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			j = 0;
			while (s[i + j] != c && s[i + j] != '\0')
				j++;
			split[count] = (char *)malloc(sizeof(char) * (j + 1));
			if (split[count] == NULL)
				return (iffaild_free(split, count));
			write_word(split[count], s + i, c);
			i += j;
			count++;
		}
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**re;
	size_t	word;

	if (!s)
		return (NULL);
	word = 0;
	word = count_words(s, c);
	re = (char **)malloc(sizeof(char *) * (word + 1));
	if (re == NULL)
		return (NULL);
	re[word] = NULL;
	return (write_split(re, s, c));
}
