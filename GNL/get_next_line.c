/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 22:00:30 by sumurata          #+#    #+#             */
/*   Updated: 2024/04/20 14:51:51 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*next = NULL;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (0);
	next = ft_readline(fd, next);
	if (!next)
		return (NULL);
	line = ft_getline(next);
	next = ft_changenext(next);
	return (line);
}

char	*ft_readline(int fd, char *next)
{
	char	*tmp;
	int		re;

	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	re = 1;
	while (!ft_strchr(next, '\n') && re != 0)
	{
		re = read(fd, tmp, BUFFER_SIZE);
		if (re == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[re] = '\0';
		next = ft_joinnext(next, tmp);
		if (!next)
		{
			free(tmp);
			return (NULL);
		}
	}
	free(tmp);
	return (next);
}

char	*ft_getline(char *next)
{
	int		i;
	char	*ret;

	i = 0;
	if (!next[i])
		return (NULL);
	while (next[i] != '\0' && next[i] != '\n')
		i++;
	ret = (char *)malloc((i + 2) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (next[i] != '\0' && next[i] != '\n')
	{
		ret[i] = next[i];
		i++;
	}
	if (next[i] == '\n')
	{
		ret[i] = '\n';
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_cpynext(int i, char *str, char *next)
{
	int	c;

	c = 0;
	i += 1;
	while (next[i])
		str[c++] = next[i++];
	str[c] = '\0';
	free(next);
	return (str);
}

char	*ft_changenext(char *next)
{
	int		len;
	int		i;
	char	*str;

	i = 0;
	len = 0;
	while (next[i] != '\0' && next[i] != '\n')
		i++;
	if (!next[i])
	{
		free(next);
		return (NULL);
	}
	str = (char *)malloc((ft_strlen(next) - i + 1) * sizeof(char));
	if (!str)
	{
		free(next);
		return (NULL);
	}
	str = ft_cpynext(i, str, next);
	return (str);
}
