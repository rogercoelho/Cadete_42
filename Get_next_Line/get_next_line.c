/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lello <lello@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:09:42 by lello             #+#    #+#             */
/*   Updated: 2024/11/20 02:04:55 by lello            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lastnode(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	if (temp == NULL)
		return (temp);
	while (temp->next_node != NULL)
		temp = temp->next_node;
	return (temp);
}

int	found_newline(t_list *lst)
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
		lst = lst->next_node;
	}
	return (0);
}

int	ft_contsize(t_list *temp)
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
		temp = temp->next_node;
	}
	return (k);
}

int	ft_cpylst(t_list *temp, char *line, int displacer)
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
		temp = temp->next_node;
	}
	return (displacer);
}

void	ft_del(t_list **lst)
{
	t_list	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next_node;
		free((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}


void	ft_lstclear(t_list **lst)
{
	t_list		*lastnod;
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

void	ft_attach(t_list **lst, char *buf)
{
	t_list	*new_node;
	t_list	*lastnod;

	if (!buf[0])
		return (free(buf));
	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		free(buf);
		return (ft_del(lst));
	}
	lastnod = ft_lastnode(lst);
	if (!lastnod)
		*lst = new_node;
	else
		lastnod->next_node = new_node;
	new_node->content = buf;
	new_node->next_node = NULL;
}

char	*ft_newline(t_list **lst, char *line, int l_line)
{
	t_list		*temp;
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

void	ft_gnl_lstnew(t_list **lst, int fd)
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
	static t_list		*lst = NULL;
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


// int	main(void)
// {
// 	int		fd;
// 	char	*rslt;

// 	fd = open("test.txt", O_RDONLY);
// 	rslt = get_next_line(fd);
// 	printf("line -> %s", rslt);
// 	return (0);
// }

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






// void	ft_clear_list(t_list **list);
// void	ft_new_list(t_list **lst, int fd);
// int		ft_new_line(t_list *lst);
// void	ft_include_node(t_list **lst, char *str);
// t_list	*ft_get_last_node(t_list **lst);

// char	*get_next_line(int fd)
// {
// 	static t_list	*list;
// 	char			*line;
// 	//int				line_size;

// 	list = NULL;
// 	line = NULL;
// 	//line_size = 0;
// 	if (read(fd, &line, 0) < 0)
// 	{
// 		ft_clear_list(&list);
// 		return (NULL);
// 	}
// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	ft_new_list(&list, fd);

// 	return (line);
// }

// void	ft_clear_list(t_list **list)
// {
// 	t_list	*temp_list;

// 	if (list == NULL)
// 		return ;
// 	while (*list != NULL)
// 	{
// 		temp_list = (*list)-> next_node;
// 		free((*list)-> content);
// 		free(*list);
// 		*list = temp_list;
// 	}
// 	*list = NULL;
// }

// void	ft_new_list(t_list **lst, int fd)
// {
// 	int		read_chars;
// 	char	*str;

// 	read_chars = 0;
// 	while (ft_new_line(*lst) == 0)
// 	{
// 		str = malloc(BUFFER_SIZE +1);
// 		if (str == NULL)
// 			return (ft_clear_list(lst));
// 		read_chars = read(fd, str, BUFFER_SIZE);
// 		if (read_chars == 0)
// 		{
// 			free(str);
// 			return ;
// 		}
// 		str[read_chars] = '\0';
// 		ft_include_node(lst, str);

// 	}


// }

// int	ft_new_line(t_list *lst)
// {
// 	int		i;

// 	if (lst == NULL)
// 		return (0);
// 	while (lst != NULL)
// 	{
// 		i = 0;
// 		while (((char *)(lst -> content))[i] != '\0' && i < BUFFER_SIZE)
// 		{
// 			if (((char *)(lst -> content))[i] == '\n')
// 				if (((char *)lst -> content)[i] == '\0')
// 					return (1);
// 			i++;
// 		}
// 		lst = lst -> next_node;
// 	}
// 	return (0);
// }

// void	ft_include_node(t_list **lst, char *str)
// {
// 	t_list	*new_node;
// 	t_list	*last_node;

// 	if (str[0] == '\0')
// 		return (free(str));
// 	new_node = malloc(sizeof(t_list));
// 	if (new_node == NULL)
// 	{
// 		free(str);
// 		return (ft_clear_list(lst));
// 	}
// 	last_node = ft_get_last_node(lst);
// 	if (last_node == NULL)
// 	{
// 		*lst = new_node;
// 	}
// 	else
// 	{
// 		last_node -> next_node = new_node;
// 		new_node -> content = str;
// 		new_node -> next_node = NULL;
// 	}
// }

// t_list	*ft_get_last_node(t_list **lst)
// {
// 	t_list	*temp_node;

// 	temp_node = *lst;
// 	if (temp_node == NULL)
// 		return (temp_node);
// 	while (temp_node -> next_node != NULL)
// 		temp_node = temp_node -> next_node;
// 	return (temp_node);
// }


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> // Para a função open


int main(void)
{
    int fd;
    char *result;

    // Abrindo um arquivo de texto em modo de leitura
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Erro ao abrir o arquivo");
        return (1);
    }

    // Chamando a função get_next_line
    result = get_next_line(fd);

    // Verificando e imprimindo o resultado (se for aplicável)
    if (result)
    {
        printf("Linha lida: %s\n", result);
        free(result);
    }
    else
    {
        printf("Nenhuma linha lida ou erro ocorreu.\n");
    }

    // Fechando o arquivo
    close(fd);

    return (0);
}
