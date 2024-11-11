/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreal-de <rreal-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:14:52 by rreal-de          #+#    #+#             */
/*   Updated: 2024/11/11 20:54:00 by rreal-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str, char const *trim)
{
	size_t	i;
	size_t	j;
	size_t	str_len;
	char	*trimmed;

	i = 0;
	j = 0;
	if (!str || !trim)
		return (NULL);
	if (str == '\0')
		ft_strdup('\0');

	while (str[i] == trim[j] && str[i] != '\0')
	{
		while (str[i] != trim[j])
		{
			str_len++;
		}
		i++;
		j++;
	}
	j = 0;
			// testar se percorre o str na condicao do trim e se incrementa o contador str_len





		return (trimmed);
	}




}
