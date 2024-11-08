/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lello <lello@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 01:37:58 by lello             #+#    #+#             */
/*   Updated: 2024/11/08 02:46:44 by lello            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*dest_loc;
	const unsigned char	*src_loc;

	dest_loc = (unsigned char *)dest;
	src_loc = (const unsigned char *) src;
	if (dest_loc == src_loc || len == 0)
		return (dest);
	if (dest_loc < src_loc)
	{
		while (len-- > 0)
		{
			*dest_loc++ = *src_loc++;
		}
	}
	else
	{
		dest_loc = dest_loc + len - 1;
		src_loc = src_loc + len - 1;
		while (len-- > 0)
		{
			*dest_loc-- = *src_loc--;
		}
	}
	return (dest);
}
