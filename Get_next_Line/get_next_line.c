/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreal-de <rreal-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:09:42 by lello             #+#    #+#             */
/*   Updated: 2024/11/20 21:45:25 by rreal-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_create_line(size_t read_chars, char *str)
{
	char	*str_return;
	size_t	i;

	i = 0;
	if (read_chars == 0)
		return (NULL);
	str_return = malloc(read_chars + 1);
	if (!str_return)
		return (NULL);
	while (i <= read_chars)
	{
		if (str[i] == '\n')
		{
			str_return[i] = '\n';
			str_return[i + 1] = '\0';
			break ;
		}
		str_return[i] = str[i];
		i++;
	}
	str_return[i] = '\n';
	str_return[i + 1] = '\0';
	return (str_return);
}

void	ft_include_node(t_list *list, char *line)
{
	while (list->next_node == NULL)
	{
		list -> content = line;
		list = list -> next_node;
	}
	list->next_node = malloc(sizeof(t_list));
	if (!list -> next_node)
		return ;
	list -> content = line;
	list -> next_node = NULL;
}



char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*str;
	char			*line;
	size_t			read_chars;
	size_t			i;

	read_chars = 0;
	i = 0;
	str = malloc(BUFFER_SIZE + 1);
	line = malloc(BUFFER_SIZE + 2);
	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	read_chars = read(fd, str, BUFFER_SIZE);
	if (read_chars < 0)
	{
		free(str);
		free(line);
		free(list);
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	line = ft_create_line (read_chars, &str[i]);
	ft_include_node(list, line);
	while (i <= read_chars)
	{
		if (str[i] == '\n')
		{
			line = ft_create_line (read_chars, &str[i + 1]);
			ft_include_node(list, line);
		}
		i++;
	}

	return (line);
}


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> // Para a função open


int main(void)
{
    int fd;
    char *result;

    // Abrindo um arquivo de texto em modo de leitura
    fd = open("./test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Erro ao abrir o arquivo");
        return (1);
    }

    // Chamando a função get_next_line
    result = get_next_line(fd);

    // Verificando e imprimindo o resultado (se for aplicável)
    if (result)
    {
        printf("Linha lida: %s\n", result);
        free(result);
    }
    else
    {
        printf("Nenhuma linha lida ou erro ocorreu.\n");
    }

    // Fechando o arquivo
    close(fd);

    return (0);
}
