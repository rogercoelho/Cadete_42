/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lello <lello@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:33:59 by rreal-de          #+#    #+#             */
/*   Updated: 2024/11/13 01:38:19 by lello            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_isalnum(int c);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *str_1, const char *str_2, size_t n);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strnstr(const char *str_big, const char *str_search, size_t len);
char	*ft_strdup(const char *str);
char	*ft_strchr(const char *string, int c);
char	*ft_strrchr(const char *string, int c);
void	*ft_memcpy(void *dest, const void *src, size_t len);
void	*ft_memmove(void *dest, const void *src, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t len);
void	*ft_memchr(const void *str, int c, size_t len);
void	*ft_memset(void *str, int c, size_t len);
void	ft_bzero(void *str, size_t len);
void	*ft_calloc(size_t num, size_t size);
char	*ft_substr(const char *str, unsigned int start, size_t len);
char	*ft_strmapi(char const *str, char (*f)(unsigned int, char));
char	*ft_strjoin(const char *str_1, const char *str_2);
char	*ft_strtrim(char const *str, char const *trim);
char	**ft_split(const char *str, char delim);
char	*ft_itoa(int n);
void	ft_striteri(char *str, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif
