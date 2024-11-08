/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lello <lello@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:59:04 by lello             #+#    #+#             */
/*   Updated: 2024/11/08 15:04:48 by lello            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t len)
{
	unsigned char	*str_loc;
	size_t			i;

	i = 0;
	str_loc = (unsigned char *)str;
	while (i < len)
	{
		str_loc[i] = 0;
		i++;
	}
}
