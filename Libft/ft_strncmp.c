/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lello <lello@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 04:39:20 by rreal-de          #+#    #+#             */
/*   Updated: 2024/10/18 02:26:54 by lello            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str_1, const char *str_2, size_t n)
{
	while ((n > 0))
	{
		if (*str_1 != *str_2)
			return ((unsigned char)*str_1 - (unsigned char)*str_2);
		if (*str_1 == '\0' || *str_2 == '\0')
			return (0);
		str_1++;
		str_2++;
		n--;
	}
	return (0);
}
