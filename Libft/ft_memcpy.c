/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lello <lello@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:53:28 by lello             #+#    #+#             */
/*   Updated: 2024/11/14 03:49:20 by lello            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char		*dest_loc;
	const unsigned char	*src_loc;

	if (!src && !dest)
		return (NULL);
	src_loc = src;
	dest_loc = dest;
	while (len > 0)
	{
		*dest_loc = *src_loc;
		dest_loc++;
		src_loc++;
		len--;
	}
	return (dest);
}
