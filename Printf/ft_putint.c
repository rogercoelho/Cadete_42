/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreal-de <rreal-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:42:31 by rreal-de          #+#    #+#             */
/*   Updated: 2025/01/10 15:50:23 by rreal-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_putint(int number)
{
	size_t	size_number;
	char	*str_number;

	size_number = 0;
	str_number = ft_itoa(number);
	size_number = ft_strlen(str_number);
	write(1, str_number, size_number);
	free(str_number);
	return (size_number);
}
