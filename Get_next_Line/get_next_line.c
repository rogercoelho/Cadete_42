/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lello <lello@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:33:18 by lello             #+#    #+#             */
/*   Updated: 2024/12/01 22:01:54 by lello            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);
char	*ft_free_mem(char *mem_tobefree, char *value_to_include);
char	*ft_rem_line_file_text(char *file_text);
char	*ft_prepare_conditions(int fd, char *file_text);
char	*ft_print_conditions(char *text_out, char **file_text);

char	*ft_free_mem(char *mem_tobefree, char *value_to_include)
{
	char	*change_mem_address;

	if (mem_tobefree == NULL)
		return (NULL);
	change_mem_address = mem_tobefree;
	mem_tobefree = value_to_include;
	free (change_mem_address);
	change_mem_address = NULL;
	return (mem_tobefree);
}

char	*ft_rem_line_file_text(char *file_text)
{
	int		i;
	int		j;
	char	*string;

	i = 0;
	j = 0;
	while (file_text[i] != '\0' && file_text[i] != '\n')
		i++;
	if (file_text[i] == '\0')
		return (free(file_text), NULL);
	string = ft_calloc((ft_strlen(file_text) - i + 1), sizeof (*file_text));
	if (string == NULL)
		return (NULL);
	while (file_text[++i] != '\0')
		string[j++] = file_text[i];
	string[j] = '\0';
	string = ft_free_mem(file_text, string);
	return (string);
}

char	*get_next_line(int fd)
{
	char		*text_out;
	static char	*file_text;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	file_text = ft_prepare_conditions(fd, file_text);
	if (file_text == NULL || file_text[0] == '\0')
	{
		free(file_text);
		file_text = NULL;
		return (NULL);
	}
	text_out = NULL;
	text_out = ft_print_conditions(text_out, &file_text);
	return (text_out);
}

char	*ft_prepare_conditions(int fd, char *file_text)
{
	char	*buffer;
	int		total_bytes;
	char	*find_newline;

	if (file_text == NULL)
		file_text = ft_calloc(1, 1);
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	total_bytes = 1;
	while (total_bytes > 0)
	{
		total_bytes = read(fd, buffer, BUFFER_SIZE);
		if (total_bytes == -1)
			return (free(file_text), free(buffer), NULL);
		buffer[total_bytes] = '\0';
		file_text = ft_strjoin(file_text, buffer);
		find_newline = ft_strchr(file_text, '\n');
		if (find_newline != NULL)
			break ;
	}
	free (buffer);
	buffer = NULL;
	return (file_text);
}

char	*ft_print_conditions(char *text_out, char **file_text)
{
	int	i;

	i = 0;
	if ((*file_text)[i] == '\0')
		return (NULL);
	while ((*file_text)[i] != '\0' && (*file_text)[i] != '\n')
		i++;
	text_out = ft_calloc((i + 2), sizeof(char));
	i = 0;
	while ((*file_text)[i] != '\0' && (*file_text)[i] != '\n')
	{
		text_out[i] = (*file_text)[i];
		i++;
	}
	if ((*file_text)[i] != '\0' && (*file_text)[i] == '\n')
		text_out[i++] = '\n';
	(*file_text) = ft_rem_line_file_text((*file_text));
	return (text_out);
}
