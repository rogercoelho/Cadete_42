/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreal-de <rreal-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 03:04:26 by rreal-de          #+#    #+#             */
/*   Updated: 2024/10/11 05:11:09 by rreal-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*duplicate;
	char	*calc;

	if (src == NULL)
		return (NULL);
	calc = malloc(strlen(src) + 1);
	if (calc == NULL)
	{
		return (NULL);
	}
	duplicate = calc;
	while (*src)
	{
		*calc++ = *src++;
	}
	*calc = '\0';
	return (duplicate);
}
