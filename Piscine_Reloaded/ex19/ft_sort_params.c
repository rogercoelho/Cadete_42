/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreal-de <rreal-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:33:25 by rreal-de          #+#    #+#             */
/*   Updated: 2024/10/05 06:43:32 by rreal-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2);
void	ft_swap(char **s1, char **s2);
void	ft_putchar(char c);
void	ft_putstr(char *str);

int	main(int nbr, char **value)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (nbr == 1)
	{
		return (0);
	}
	while (i++ < nbr)
	{
		if (ft_strcmp(value[j], value[j +1]) > 0)
		{
			ft_swap(&value[j], &value[j + 1]);
		}
		i = 1;
		while (i++ < nbr)
		{
			ft_putstr(value[j]);
			j++;
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
	ft_putchar('\n');
}
