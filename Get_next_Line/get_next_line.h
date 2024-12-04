/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreal-de <rreal-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:23:58 by rreal-de          #+#    #+#             */
/*   Updated: 2024/12/03 23:03:08 by rreal-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *str_1, const char *str_2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *string, int c);
void	*ft_calloc(size_t num, size_t size);
char	*ft_free_mem(char *mem_tobefree, char *value_to_include);
char	*ft_rem_line_file_text(char *file_text);
char	*ft_prepare_conditions(int fd, char *file_text);
char	*ft_print_conditions(char *text_out, char **file_text);

#endif
