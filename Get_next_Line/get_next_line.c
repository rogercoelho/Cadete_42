/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreal-de <rreal-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:09:42 by lello             #+#    #+#             */
/*   Updated: 2024/11/21 19:25:43 by rreal-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_create_line(int *read_chars, char *str, int *i)
{
	char	*str_return;
	int		j;

	if (read_chars == 0)
		return (NULL);
	str_return = (char *)malloc((*read_chars) + 1);
	if (!str_return)
		return (NULL);
	j = 0;
	while (j < *read_chars && str[*i] != '\n')
	{
		str_return[j] = str[*i];
		j++;
		(*i)++;
	}
	if (str[*i] == '\n')
	{
		str_return[j] = '\n';
		j++;
	}
	str_return[j] = '\0';
	return (str_return);
}

void	ft_include_node(t_list *list, char *line)
{
	list->content = line;
	list->next_node = NULL;
}

static int	node_verify(t_list *list)
{
	if (list->content == NULL)
		return (0);
	return (1);
}

char	*validate(int *i, int *read_chars, char *str, char *line)
{
	static t_list	*list;

	list = malloc(sizeof(t_list));
	node_verify(list);
	while (i <= read_chars)
	{
		if (str[*i] != '\n')
		{
			line = ft_create_line (read_chars, str, i);
			ft_include_node(list, line);
			break ;
		}
		if (str[*i] == '\n')
		{
			i++;
			if (str[*i] == '\0')
				return (NULL);
			line = ft_create_line (read_chars, str, i);
			ft_include_node(list, line);
			break ;
		}
		i++;
	}
	free(list);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	static int	read_chars;
	static int	i;

	line = malloc(BUFFER_SIZE + 2);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read_chars == 0)
	{
		str = malloc(BUFFER_SIZE + 1);
		read_chars = read(fd, str, BUFFER_SIZE);
	}
	if (read_chars < 0)
		return (free(str), free(line), NULL);
	line = validate(&i, &read_chars, str, line);
	return (line);
}


#include <fcntl.h>  // Para open()
#include <stdio.h>  // Para printf()
#include <stdlib.h> // Para free()
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    // Abrir o arquivo "test.txt" no modo somente leitura
    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Erro ao abrir o arquivo");
        return (1);
    }

    // Ler e imprimir cada linha até que `get_next_line` retorne NULL
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line); // Imprimir a linha
        free(line);         // Liberar a memória alocada por `get_next_line`
    }

    // Fechar o arquivo
    close(fd);

    return (0);
}
