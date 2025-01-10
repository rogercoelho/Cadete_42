/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreal-de <rreal-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:43:46 by rreal-de          #+#    #+#             */
/*   Updated: 2025/01/10 15:43:58 by rreal-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_unsig(unsigned int n)
{
	int		cnt;
	char	c;

	cnt = 0;
	if (n >= 10)
		cnt += ft_putint(n / 10);
	c = (n % 10) + '0';
	cnt += ft_putchar(c);
	return (cnt);
}
