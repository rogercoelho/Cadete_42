/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreal-de <rreal-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:33:25 by rreal-de          #+#    #+#             */
/*   Updated: 2024/10/09 22:56:41 by rreal-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2);
void	ft_swap(char **s1, char **s2);
void	ft_putstr(char *str);
void	ft_putchar(char c);

int	main(int argc, char **argv)
{
	int	i;
	int	sorted;

	if (argc > 1)
	{
		sorted = 0;
		while (sorted != 1)
		{
			sorted = 1;
			i = 1;
			while (i < argc - 1)
			{
				if (ft_strcmp(argv[i], argv[i + 1]) > 0)
					ft_swap(&argv[i], &argv[i + 1]);
				sorted = 0;
				i++;
			}
		}
		i = 1;
		while (i < argc)
		{
			ft_putstr(argv[i++]);
		}
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_swap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}
