/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lello <lello@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:38:13 by lello             #+#    #+#             */
/*   Updated: 2024/11/08 00:15:49 by lello            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	str_len;

	str_len = ft_strlen(str);
	while (str_len > 0)
	{
		if (str[str_len] == (char)c)
		{
			return ((char *) str + str_len);
		}
		str_len--;
	}
	if (str[str_len] == (char)c)
	{
		return ((char *)str + str_len);
	}
	return (NULL);
}
