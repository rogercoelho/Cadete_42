/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreal-de <rreal-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:40:19 by rreal-de          #+#    #+#             */
/*   Updated: 2025/01/10 16:08:30 by rreal-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static void	ft_format(char type, va_list valist, int *cnt)
{
	if (type == 'c')
		*cnt += ft_putchar(va_arg(valist, int));
	if (type == 's')
		*cnt += ft_putstr(va_arg(valist, char *));
	if (type == 'd' || type == 'i')
		*cnt += ft_putint(va_arg(valist, int));
	if (type == 'p')
		*cnt += ft_putpointer(va_arg(valist, unsigned long));
	if (type == 'u')
		*cnt += ft_unsig(va_arg(valist, unsigned int));
	if (type == 'x' || type == 'X')
		*cnt += ft_puthex(va_arg(valist, unsigned int), type);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		cnt;
	va_list	valist;

	i = 0;
	cnt = 0;
	if (!str)
		return (-1);
	va_start(valist, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
				cnt += ft_putchar('%');
			else
				ft_format(str[i], valist, &cnt);
		}
		else
			cnt += ft_putchar(str[i]);
		i++;
	}
	return (cnt);
}
