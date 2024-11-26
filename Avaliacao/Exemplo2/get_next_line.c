/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreal-de <rreal-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:36:12 by lumfred           #+#    #+#             */
/*   Updated: 2024/11/20 18:09:29 by rreal-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	if (*str == '\0')
	{
		if ((char)c == '\0')
			return (str);
		return (NULL);
	}
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (*str == (char)c)
		return (str);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (str);
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*str;
	char	*tmp;

	len = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	tmp = str;
	while (len--)
		*str++ = *s1++;
	*str = '\0';
	return (tmp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	char	*tmp;

	tmp = s1;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (*tmp != '\0')
		str[i++] = *tmp++;
	while (*s2 != '\0')
		str[i++] = *s2++;
	str[i] = '\0';
	free(s1);
	return (str);
}



char	*make_line(char **str, int chars, char **buf)
{
	int		index;
	char	*line;
	char	*tmp;

	free(*buf);
	tmp = NULL;
	if (chars < 0 || *str == NULL)
		return (NULL);
	if (!chars && !ft_strchr(*str, '\n'))
	{
		line = ft_strdup(*str);
		free(*str);
		*str = NULL;
		return (line);
	}
	index = 0;
	while ((*str)[index] != '\n')
		index++;
	line = ft_substr(*str, 0, index + 1);
	if ((int)ft_strlen(*str) - index - 1 >= 1)
		tmp = ft_substr(*str, index + 1, ft_strlen(*str) - index - 1);
	free(*str);
	*str = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	char		*tmp;
	int			chars;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	chars = read(fd, buf, BUFFER_SIZE);
	while (chars > 0)
	{
		buf[chars] = '\0';
		if (!str)
			tmp = ft_strdup(buf);
		else
			tmp = ft_strjoin(str, buf);
		str = tmp;
		if (ft_strchr(str, '\n'))
			break ;
		chars = read(fd, buf, BUFFER_SIZE);
	}
	return (make_line(&str, chars, &buf));
}



#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> // Para a função open


int main(void)
{
    int fd;
	char *result = "1";

    // Abrindo um arquivo de texto em modo de leitura
    fd = open("./test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Erro ao abrir o arquivo");
        return (1);
    }

    // Chamando a função get_next_line

    // Verificando e imprimindo o resultado (se for aplicável)
    while (result)
    {
		 result = get_next_line(fd);
        printf("Linha lida: %s\n", result);
        free(result);
    }

    // Fechando o arquivo
    close(fd);

    return (0);
}
