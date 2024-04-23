/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:15:49 by sumurata          #+#    #+#             */
/*   Updated: 2024/04/23 18:53:28 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 10

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

void	*ft_memcpy(void *buf1, const void *buf2, size_t n)
{
	char		*b1;
	const char	*b2;
	size_t		i;

	b1 = buf1;
	b2 = buf2;
	i = 0;
	if (b1 == NULL && b2 == NULL)
		return (NULL);
	while (i < n)
	{
		b1[i] = b2[i];
		i++;
	}
	return (buf1);
}

char	*ft_joinnext(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*next;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	next = (char *)malloc(len1 + len2 + 1);
	if (!next)
	{
		free(s1);
		return (NULL);
	}
	ft_memcpy(next, (char *)s1, len1);
	ft_memcpy(next + len1, (char *)s2, len2 + 1);
	if (s1)
		free(s1);
	return (next);
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
	int		c;
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

char	*get_next_line(int fd)
{
	char		*line;
	static char	*next = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	next = ft_readline(fd, next);
	if (!next)
		return (NULL);
	line = ft_getline(next);
	next = ft_changenext(next);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	line = "";
	fd = open("test.txt", O_RDONLY);
	while (line)
	{
		line = get_next_line(fd);
		printf("> %s", line);
		free(line);
	}
	return (0);
}
