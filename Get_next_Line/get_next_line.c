/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreal-de <rreal-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:17:23 by rreal-de          #+#    #+#             */
/*   Updated: 2024/11/18 20:39:48 by rreal-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*my_list;

	my_list = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_lstnew(my_list);
	if (!my_list)
		return (NULL);
	return ((char *) my_list);
}
