/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreal-de <rreal-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:26:57 by rreal-de          #+#    #+#             */
/*   Updated: 2024/11/15 19:36:38 by rreal-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);

	while (lst -> next != NULL)
	{
		lst = lst -> next;
	}
	return (lst);
}


void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst || new == NULL)
		return ;

	if (lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
}
