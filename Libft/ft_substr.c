/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lello <lello@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:32:38 by lello             #+#    #+#             */
/*   Updated: 2024/11/14 04:50:50 by lello            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char			*str_loc;
	unsigned int	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	if (len > ft_strlen(str) - start)
		len = ft_strlen(str) - start;
	if (start >= ft_strlen(str))
	{
		str_loc = (char *)malloc(sizeof(char));
		if (str_loc != NULL)
			str_loc[0] = '\0';
		return (str_loc);
	}
	str_loc = (char *)malloc(sizeof(char) * (len + 1));
	if (str_loc == NULL)
		return (NULL);
	while (i < len)
		str_loc[i++] = str[start++];
	str_loc[i] = '\0';
	return (str_loc);
}
