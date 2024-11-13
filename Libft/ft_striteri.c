/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lello <lello@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 00:28:44 by lello             #+#    #+#             */
/*   Updated: 2024/11/13 00:59:28 by lello            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

void	ft_striteri(char *str, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (str == NULL || !f)
		return ;
	if (str != NULL && f)
	{
		while (str[i] != '\0' || str[i])
		{
			f(i, &str[i]);
			i++;
		}
	}
}
