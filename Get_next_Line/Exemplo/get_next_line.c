/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lello <lello@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:42:24 by deordone          #+#    #+#             */
/*   Updated: 2024/11/20 01:53:42 by lello            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


t_gnl_list	*ft_lastnode(t_gnl_list **lst)
{
	t_gnl_list	*temp;

	temp = *lst;
	if (temp == NULL)
		return (temp);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

int	found_newline(t_gnl_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	while (lst)
	{
		i = 0;
		while (lst->content[i] && i < BUFFER_SIZE)
		{
			if (lst->content[i] == '\n' || lst->content[i] == '\0')
				return (1);
			++i;
		}
		lst = lst->next;
	}
	return (0);
}

int	ft_contsize(t_gnl_list *temp)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (temp)
	{
		i = 0;
		while (temp->content[i])
		{
			if (temp->content[i] == '\n')
				return (++k);
			++i;
			++k;
		}
		temp = temp->next;
	}
	return (k);
}

int	ft_cpylst(t_gnl_list *temp, char *line, int displacer)
{
	int	i;

	while (temp)
	{
		i = 0;
		while (temp->content[i] != '\0')
		{
			if (temp->content[i] == '\n')
				return (line[displacer++] = temp->content[i]);
			else
				line[displacer++] = temp->content[i++];
		}
		temp = temp->next;
	}
	return (displacer);
}

void	ft_del(t_gnl_list **lst)
{
	t_gnl_list	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}


void	ft_lstclear(t_gnl_list **lst)
{
	t_gnl_list	*lastnod;
	int			i;
	int			k;
	char		*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (ft_del(lst));
	lastnod = ft_lastnode(lst);
	i = 0;
	k = 0;
	while (lastnod->content[i] != '\0' && lastnod->content[i] != '\n')
		++i;
	while (lastnod->content[i] != '\0' && lastnod->content[++i])
		buf[k++] = lastnod->content[i];
	buf[k] = '\0';
	ft_del(lst);
	ft_attach(lst, buf);
}

void	ft_attach(t_gnl_list **lst, char *buf)
{
	t_gnl_list	*new_node;
	t_gnl_list	*lastnod;

	if (!buf[0])
		return (free(buf));
	new_node = malloc(sizeof(t_gnl_list));
	if (!new_node)
	{
		free(buf);
		return (ft_del(lst));
	}
	lastnod = ft_lastnode(lst);
	if (!lastnod)
		*lst = new_node;
	else
		lastnod->next = new_node;
	new_node->content = buf;
	new_node->next = NULL;
}

char	*ft_newline(t_gnl_list **lst, char *line, int l_line)
{
	t_gnl_list	*temp;
	int			displacer;

	temp = *lst;
	displacer = 0;
	l_line += ft_contsize(temp);
	line = (char *)malloc(sizeof(char) * (l_line + 1));
	if (!line)
	{
		ft_del(lst);
		return (NULL);
	}
	displacer = ft_cpylst(temp, line, displacer);
	line[l_line] = '\0';
	return (line);
}

void	ft_gnl_lstnew(t_gnl_list **lst, int fd)
{
	int		char_read;
	char	*buf;

	char_read = 0;
	while (!found_newline(*lst))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (NULL == buf)
			return (ft_del(lst));
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		ft_attach(lst, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*lst = NULL;
	char				*line;
	int					l_line;

	line = NULL;
	l_line = 0;
	if (read(fd, &line, 0) < 0)
	{
		ft_del(&lst);
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_gnl_lstnew(&lst, fd);
	if (lst == NULL)
		return (NULL);
	line = ft_newline(&lst, line, l_line);
	if (lst == NULL)
		return (NULL);
	ft_lstclear(&lst);
	return (line);
}


int	main(void)
{
	int		fd;
	char	*rslt;

	fd = open("test.txt", O_RDONLY);
	rslt = get_next_line(fd);
	printf("line -> %s", rslt);
	return (0);
}

/*
int	main(void)
{
	int		fd;
	char	*putito;

	fd = open("test.txt", O_RDONLY);
	putito = get_next_line(fd);
	while (putito)
	{
		printf("%s", putito);
		free(putito);
		putito = get_next_line(fd);
	}
	close(fd);
	return (0);
}*/
