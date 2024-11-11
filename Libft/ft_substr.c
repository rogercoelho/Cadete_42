/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lello <lello@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:32:38 by lello             #+#    #+#             */
/*   Updated: 2024/11/11 13:45:05 by lello            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*str_loc;
	size_t	i;
	size_t	j;

	str_loc = (char *)malloc(len + 1);
	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (i >= start && j < len)
		{
			str_loc[j] = str[i];
			j++;
		}
		i++;
	}
	str_loc[j] = '\0';
	return (str_loc);
}
