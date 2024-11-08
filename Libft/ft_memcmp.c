/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lello <lello@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 03:00:22 by lello             #+#    #+#             */
/*   Updated: 2024/11/08 03:16:50 by lello            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	const unsigned char	*s1_loc;
	const unsigned char	*s2_loc;
	size_t				i;

	s1_loc = (const unsigned char *)s1;
	s2_loc = (const unsigned char *)s2;
	i = 0;
	while (i < len)
	{
		if (s1_loc[i] != s2_loc[i])
		{
			return (s1_loc[i] - s2_loc[i]);
		}
		i++;
	}
	return (0);
}
