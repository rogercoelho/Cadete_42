/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lello <lello@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:17:16 by rreal-de          #+#    #+#             */
/*   Updated: 2024/12/01 21:59:43 by lello            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *str_1, const char *str_2)
{
	char	*str_join;
	size_t	str_len1;
	size_t	str_len2;

	if (str_1 == NULL || str_2 == NULL)
		return (NULL);
	str_len1 = ft_strlen(str_1);
	str_len2 = ft_strlen(str_2);
	str_join = malloc((str_len1 + str_len2) + 1);
	if (str_join == NULL)
		return (NULL);
	ft_strlcpy(str_join, str_1, (str_len1 + 1));
	ft_strlcpy(&str_join[str_len1], str_2, (str_len2 + 1));
	free (str_1);
	str_1 = NULL;
	return (str_join);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize > 0)
	{
		i = 0;
		while (i < dstsize - 1)
		{
			if (src[i] == '\0')
				break ;
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlen(const char *str)
{
	size_t	lenght;

	lenght = 0;
	while (str[lenght] != '\0')
	{
		lenght++;
	}
	return (lenght);
}

char	*ft_strchr(const char *string, int c)
{
	while (*string != '\0' && *string != (char) c)
	{
		string++;
	}
	if (*string != (char)c)
	{
		return (NULL);
	}
	return ((char *)string);
}

void	*ft_calloc(size_t num, size_t size)
{
	size_t	total_mem_size;
	char	*str;
	size_t	i;

	total_mem_size = num * size;
	str = malloc(total_mem_size);
	if (str == 0)
		return (NULL);
	i = 0;
	while (i < total_mem_size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
