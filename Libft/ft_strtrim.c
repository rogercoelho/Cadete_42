/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lello <lello@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:14:52 by rreal-de          #+#    #+#             */
/*   Updated: 2024/11/12 03:09:01 by lello            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_chartocharcmp(char c, const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *str, char const *trim)
{
	char	*str_loc;
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(str);
	while (str[start] != '\0' && ft_chartocharcmp(str[start], trim) != 0)
	{
		start++;
	}
	while (end > start && ft_chartocharcmp(str[end - 1], trim) != 0)
	{
		end--;
	}
	str_loc = (char *)malloc((end - start) + 1);
	if (str_loc == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(str_loc, &str[start], (end - start) + 1);
	return (str_loc);
}
