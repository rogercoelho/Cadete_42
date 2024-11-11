/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreal-de <rreal-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:32:51 by rreal-de          #+#    #+#             */
/*   Updated: 2024/11/11 20:09:09 by rreal-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(const char *str_1, const char *str_2)
{
	char	*str_join;
	size_t	str_len1;
	size_t	str_len2;

	if (str_1 == NULL || str_2 == NULL)
		return (NULL);
	str_len1 = ft_strlen(str_1);
	str_len2 = ft_strlen(str_2);
	str_join = malloc((str_len1 + str_len2) + 1);
	if (str_join == NULL)
		return (NULL);
	ft_strlcpy(str_join, str_1, (str_len1 + 1));
	ft_strlcpy(&str_join[str_len1], str_2, (str_len2 + 1));
	return (str_join);
}
