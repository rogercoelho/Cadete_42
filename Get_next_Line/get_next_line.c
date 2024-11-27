/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lello <lello@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:09:42 by lello             #+#    #+#             */
/*   Updated: 2024/11/27 14:55:10 by lello            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_fd_text(int fd, char *fd_text);
void	*ft_calloc(size_t num, size_t size);
void	*ft_memset(void *str, int c, size_t len);

char	*get_next_line(int fd)
{
	char		*line_out;
	static char	*fd_text;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fd_text = read_fd_text(fd, fd_text);
}

char	*read_fd_text(int fd, char *fd_text)
{
	int		total_bytes;
	char	*text_buffer;

	if (fd_text == NULL)
		fd_text = ft_calloc(1, 1);
	text_buffer = calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!text_buffer)
		return (NULL);
	total_bytes = 1;
	while (total_bytes > 0)
	{
		total_bytes = read(fd, text_buffer, BUFFER_SIZE);
	}
}

void	*ft_calloc(size_t num, size_t size)
{
	size_t	total_mem_size;
	void	*str;

	total_mem_size = num * size;
	str = malloc(total_mem_size);
	if (str == 0)
	{
		return (NULL);
	}
	ft_memset(str, 0, total_mem_size);
	return (str);
}

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*str_loc;
	size_t			i;

	i = 0;
	str_loc = (unsigned char *)str;
	while (i < len)
	{
		str_loc[i] = (unsigned char)c;
		i++;
	}
	return (str);
}


#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>




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
