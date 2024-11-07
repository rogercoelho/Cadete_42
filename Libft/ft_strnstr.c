/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreal-de <rreal-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:04:18 by rreal-de          #+#    #+#             */
/*   Updated: 2024/11/07 19:52:23 by rreal-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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

int	main(void)
{
	size_t		len;
	char		*result;
	const char	*big = "lorem ipsum dolor sit amet";
	const char	*search1 = "dol";


	len = 30;
	result = ft_strnstr(big, search1, len);
	if (result)
		printf("Substring '%s' encontrada: '%s'\n", search1, result);
	else
		printf("Substring '%s' não encontrada.\n", search1);

	return (0);
}
