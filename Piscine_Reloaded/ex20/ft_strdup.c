/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreal-de <rreal-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 03:04:26 by rreal-de          #+#    #+#             */
/*   Updated: 2024/10/11 05:58:09 by rreal-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*duplicate;
	char	*calc;

	if (src == NULL)
		return (NULL);
	calc = malloc(ft_strlen(src) + 1);
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

int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}
