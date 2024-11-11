/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lello <lello@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:03:07 by lello             #+#    #+#             */
/*   Updated: 2024/11/11 15:06:50 by lello            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char			*str_loc;
	size_t			i;

	i = 0;
	if (!str || !f)
	{
		return (NULL);
	}
	str_loc = ft_strdup(str);
	if (!str_loc)
		return (NULL);
	while (str[i] != '\0')
	{
		str_loc[i] = f(i, str[i]);
		i++;
	}
	return (str_loc);
}
