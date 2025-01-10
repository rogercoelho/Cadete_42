/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreal-de <rreal-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:40:45 by rreal-de          #+#    #+#             */
/*   Updated: 2025/01/10 16:02:22 by rreal-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char letter);
int		ft_strlen(char *str);
int		ft_putstr(char *str);
char	*ft_itoa(int number);
int		ft_putint(int number);
int		ft_putpointer(unsigned long pnt);
int		ft_unsig(unsigned int n);
int		ft_puthex(unsigned long value, char specifier);

#endif
