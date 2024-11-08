/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lello <lello@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:04:18 by rreal-de          #+#    #+#             */
/*   Updated: 2024/11/07 22:02:35 by lello            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *bigstr, const char *search, size_t len)
{
	size_t	i;
	size_t	search_len;

	search_len = ft_strlen(search);
	if (search_len == '\0')
		return ((char *)bigstr);
	if (len == 0)
		return (NULL);
	i = 0;
	while (bigstr[i] != '\0' && i <= len - search_len)
	{
		if (bigstr[i] == search[0])
		{
			if (ft_strncmp(bigstr + i, search, search_len) == 0)
				return ((char *)bigstr + i);
		}
		i++;
	}
	return (NULL);
}
