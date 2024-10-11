/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreal-de <rreal-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 03:04:26 by rreal-de          #+#    #+#             */
/*   Updated: 2024/10/11 05:05:18 by rreal-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
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

int	main(void)
{
	char	*str_src;
	char	*str_cpy;

	str_src = "teste de copia!!";
	str_cpy = ft_strdup(str_src);
	printf("Origem --> %s\n", str_src);
	printf("Copia --> %s\n", str_cpy);
}


