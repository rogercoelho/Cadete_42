/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lello <lello@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:49:39 by lello             #+#    #+#             */
/*   Updated: 2024/11/08 14:55:14 by lello            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*str_loc;
	size_t			i;

	i = 0;
	str_loc = (unsigned char *)str;
	while (i < len)
	{
		str_loc[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
