/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreal-de <rreal-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 04:39:20 by rreal-de          #+#    #+#             */
/*   Updated: 2024/10/17 05:21:59 by rreal-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *str_1, const char *str_2, unsigned int n)
{
	int	i;

	i = 0;
	while ((str_1[i] || str_2[i]) && (str_1[i] || str_2[i] <= n) && (str_1[i] == str_2[i]))
	{
		str_1++;
		str_2++;
	}
	return (str_1 - str_2);
}

int	main(void)
{
	ft_strncmp("apple", "appa", 4);
}
