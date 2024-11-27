/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lello <lello@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:09:42 by lello             #+#    #+#             */
/*   Updated: 2024/11/27 02:59:37 by lello            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_create_line(int read_chars, char *str, int *val_i)
{
	char	*str_return;
	int		j;
	int		i;

	i = *val_i;
	if (read_chars == 0)
		return (NULL);
	str_return = (char *)malloc((read_chars) + 1);
	if (!str_return)
		return (NULL);
	j = 0;
	while (j < read_chars && str[i] != '\n')
	{
		str_return[j] = str[i];
		j++;
		i++;
	}
	if (str[i] == '\n')
	{
		str_return[j] = '\n';
		j++;
	}
	str_return[j] = '\0';
	*val_i = i;
	return (str_return);
}

char	*validate(int read_chars, char *str, int *i, char *line)
{
	static int	val_i;

	while (val_i <= read_chars)
	{
		if (str[val_i] != '\n')
		{
			line = ft_create_line(read_chars, str, &val_i);
			break ;
		}
		if (str[val_i] == '\n')
		{
			(val_i)++;
			if (str[val_i] == '\0')
				break ;
			line = ft_create_line(read_chars, str, &val_i);
			break ;
		}
		val_i++;
	}
	*i = val_i;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	static int	read_chars;
	static int	i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read_chars == 0)
	{
		str = malloc(BUFFER_SIZE + 1);
		if (!str)
			return (NULL);
		read_chars = read(fd, str, BUFFER_SIZE);
	}
	if (read_chars < 0)
		free(str);
		return (NULL);

	line = validate(read_chars, str, &i, NULL);
	if (i == read_chars)
	{
		free(str);
		str = malloc(BUFFER_SIZE + 1);
		if (!str)
			return (NULL);
		read_chars = read(fd, str, BUFFER_SIZE);
		i = 0;
		if (read_chars <= 0)
		{
			free(str);
			return (NULL);
		}
	}
	return (line);
}
