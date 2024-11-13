/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lello <lello@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 03:17:33 by lello             #+#    #+#             */
/*   Updated: 2024/11/12 20:08:16 by lello            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_counter(const char *str, char delim)
{
	size_t	word_counter;
	size_t	i;

	word_counter = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && str[i] != delim)
		{
			word_counter++;
		}
		if (i > 0 && str[i] != delim && str[i - 1] == delim)
		{
			word_counter++;
		}
		i++;
	}
	return (word_counter);
}

char	*ft_allocate_word(const char *str, size_t start, size_t end)
{
	char	*word;

	word = malloc((end - start + 2) * sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, str + start, end - start + 2);
	return (word);
}

char	**ft_malloc_strs(char **strs, const char *str, char delim)
{
	size_t	i;
	size_t	start;
	size_t	word_index;

	i = 0;
	start = 0;
	word_index = 0;
	while (str[i] != '\0')
	{
		if (str[i] != delim && (i == 0 || str[i - 1] == delim))
			start = i;
		if ((str[i] != delim && str[i + 1] == '\0')
			|| (str[i] != delim && str[i + 1] == delim))
		{
			strs[word_index] = ft_allocate_word(str, start, i);
			if (!strs[word_index])
				return (NULL);
			word_index++;
		}
		i++;
	}
	return (strs);
}

char	**ft_split(const char *str, char delim)
{
	char	**strs;
	size_t	wordcount;

	wordcount = ft_counter(str, delim);
	strs = malloc(sizeof(*strs) * (wordcount + 1));
	if (!strs)
		return (NULL);
	if (ft_malloc_strs(strs, str, delim) == NULL)
		return (NULL);
	strs[wordcount] = NULL;
	return (strs);
}
