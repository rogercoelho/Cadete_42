/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreal-de <rreal-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:33:59 by rreal-de          #+#    #+#             */
/*   Updated: 2024/11/11 20:15:52 by rreal-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>

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

#endif
