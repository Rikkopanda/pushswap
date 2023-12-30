/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:17:24 by rverhoev          #+#    #+#             */
/*   Updated: 2023/10/31 10:17:26 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h>
#include <string.h>

char	*make_next_line(t_list **list, int size)
{
	t_list	*node;
	char	*bigstring;
	char	*placeholder;

	bigstring = malloc(sizeof(char) * size + 1);
	if (!bigstring)
		return (NULL);
	placeholder = bigstring;
	while (size >= 0)
		bigstring[size--] = '\0';
	node = *list;
	while (node != NULL)
	{
		size = 0;
		while (node->buffer[size])
		{
			*bigstring++ = node->buffer[size];
			if (node->buffer[size] == '\n')
				return (placeholder);
			size++;
		}
		node = node->next;
	}
	return (placeholder);
}

char	*ret_next_line(t_list **list)
{
	int		size;
	int		i;
	t_list	*node;

	size = 1;
	i = 0;
	node = *list;
	while (node != NULL)
	{
		while (node->buffer[i])
		{
			if (node->buffer[i] == '\n')
				size = size + i + 1;
			i++;
		}
		if (node->buffer[i] == '\n')
			break ;
		size = size + i;
		i = 0;
		node = node->next;
	}
	if (size > 1)
		return (make_next_line(list, size));
	else
		return (NULL);
}

char	*create_list(int fd, t_list **list)
{
	char	*buff_str;
	t_list	*new_node;
	t_list	*last_node;
	int		i;

	i = 0;
	buff_str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff_str)
		return (NULL);
	while (i <= BUFFER_SIZE)
		buff_str[i++] = '\0';
	last_node = *list;
	while (find_newline(last_node))
	{
		i = read(fd, buff_str, BUFFER_SIZE);
		if (!i)
			break ;
		buff_str[i] = '\0';
		new_node = ft_lstnew_strdup(buff_str);
		if (!new_node)
			return (NULL);
		lstlast0_lstback1(list, new_node, 1);
		last_node = lstlast0_lstback1(list, NULL, 0);
	}
	return (buff_str);
}
//fif NULL, free wordt gedaan later
// callocte eerst aleen buf_size, daardoor geen \0 en 
//-dus invalid write bij andere functie
//malloc lstbuffer & lst
//add to back if there is list, else make *lst = new

void	create_leftover(t_list **list, char *left_over_str)
{
	t_list	*new_node;
	int		i;

	i = 0;
	left_over_str = ft_strchr(left_over_str, '\n') + 1;
	while (1)
	{
		new_node = ft_lstnew_strdup(&left_over_str[i]);
		if (!new_node)
			break ;
		while (left_over_str[i] != '\n' && left_over_str[i])
			i++;
		lstlast0_lstback1(list, new_node, 1);
		if (!left_over_str[i] || !left_over_str[i + 1])
			break ;
		i++;
	}
}
// doesnt trim after \n but ok
//add to back if there is list, else make *lst = new
// in case last char in buff = \n or last = \0
//printf("\nleftover =  %s", left_over_str);
//printf("first after leftover %s", (*list)->next->next->buffer);
//size_of_total_str(list);

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*last_buff;
	char			*next_line;

	next_line = NULL;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (read(fd, next_line, 0) < 0)
		return (NULL);
	last_buff = create_list(fd, &list);
	if (last_buff == NULL)
		return (free(last_buff), ft_lstclear(&list), NULL);
	next_line = ret_next_line(&list);
	if (next_line == NULL)
		return (free(last_buff), ft_lstclear(&list), NULL);
	ft_lstclear(&list);
	if (ft_strchr(last_buff, '\n') && *(ft_strchr(last_buff, '\n') + 1))
		create_leftover(&list, last_buff);
	free(last_buff);
	return (next_line);
}
//clear all untill first newline, 
//-then make first node the subsequent node if after newline excists.
// read untill newline.
// fill whole newlines into seperate nodes. if createlist gave a leftover.
//	H	a	l	l	l	l	l	l	\n
//	w	a	a	d	w	a	d	w	\n
//	a	d	w	a	a	w	w	a	\n
//printf("first buffer %s", list->buffer);
//printf("new ? %s", list->buffer);
