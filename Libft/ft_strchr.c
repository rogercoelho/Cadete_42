/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lello <lello@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:30:26 by lello             #+#    #+#             */
/*   Updated: 2024/11/08 00:48:22 by lello            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int c)
{
	while (*string != '\0' && *string != (char) c)
	{
		string++;
	}
	if (*string != (char)c)
	{
		return (NULL);
	}
	return ((char *)string);
}
