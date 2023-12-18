/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumurata <sumurata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:53:51 by sumurata          #+#    #+#             */
/*   Updated: 2023/12/18 11:44:49 by sumurata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_tolower(char *c);
ssize_t	ft_putchar_fd(char c, int fd);
ssize_t	ft_putstr_fd(char *s, int fd);
int		ft_c_char(char c);
int		ft_s_char(char *str);
char	*ft_itoa(int n);
char	*ft_convertbase16(unsigned long long num);
int		ft_p_voidp(unsigned long long point);
int		ft_di_int(int i);
int		ft_putcount(char *c);
int		ft_printf(const char *input, ...);
int		ft_put_identifer(int c, va_list args);
int		ft_u_ull(unsigned int u);
int		ft_xlx_ui(unsigned int i, int f);
int		ft_output(const char *tmp, va_list args);

#endif