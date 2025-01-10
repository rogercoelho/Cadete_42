/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreal-de <rreal-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:43:29 by rreal-de          #+#    #+#             */
/*   Updated: 2025/01/10 15:49:50 by rreal-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_strlen(char *str)
{
	int	str_length;

	str_length = 0;
	if (!str)
		return (str_length);
	while (str[str_length])
		str_length++;
	return (str_length);
}
