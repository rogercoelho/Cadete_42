/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lello <lello@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:15:09 by lello             #+#    #+#             */
/*   Updated: 2024/11/08 15:27:01 by lello            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	size_t	total_mem_size;
	void	*str;

	total_mem_size = num * size;
	str = malloc(total_mem_size);
	if (str == 0)
	{
		return (NULL);
	}
	ft_memset(str, 0, total_mem_size);
	return (str);
}
