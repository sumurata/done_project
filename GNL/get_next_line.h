/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 22:01:18 by sumurata          #+#    #+#             */
/*   Updated: 2024/04/20 21:13:48 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_joinnext(char *s1, char *s2);
void	*ft_memcpy(void *buf1, const void *buf2, size_t n);
char	*get_next_line(int fd);
char	*ft_readline(int fd, char *next);
char	*ft_getline(char *next);
char	*ft_changenext(char *next);
char	*ft_cpynext(int i, char *str, char *next);

#endif