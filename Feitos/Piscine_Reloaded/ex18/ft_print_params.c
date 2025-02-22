/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreal-de <rreal-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:03:39 by rreal-de          #+#    #+#             */
/*   Updated: 2024/10/09 22:55:48 by rreal-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_params(char **argv)
{
	while (*argv)
	{
		while (**argv)
		{
			ft_putchar(*(*argv)++);
		}
		ft_putchar('\n');
		++(argv);
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_print_params(++argv);
	}
	return (0);
}
