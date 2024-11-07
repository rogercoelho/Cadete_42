/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lello <lello@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:57:24 by rreal-de          #+#    #+#             */
/*   Updated: 2024/11/05 22:19:26 by lello            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *search, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*search == '\0')
	{
		return (big);
	}
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (search[j] != '\0' && big[i + j] == search[j] && (i + j) < len)
		{
			j++;
			if (search[j] == '\0')
			{
				return (big[i]);
			}
		}
		i++;
	}
	return (NULL);
}

int	main(void)
{
	const char	*haystack = "Hello, world!";
	const char	*needle = "world";
	char		*result;

	result = ft_strnstr(haystack, needle, 10);
	if (result)
		printf("Found: \"%s\"\n", result);
	else
		printf("Not found within limit\n");
	return (0);
}
