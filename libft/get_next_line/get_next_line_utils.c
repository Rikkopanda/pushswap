/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:17:44 by rverhoev          #+#    #+#             */
/*   Updated: 2023/10/31 10:17:46 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s1;

	if (!s)
		return (NULL);
	s1 = (char *)s;
	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == c)
		{
			s1 = &s1[i];
			return (s1);
		}
		i++;
	}
	if (s1[i] == c)
		return (&s1[i]);
	return (NULL);
}

t_list	*ft_lstnew_strdup(void *buffer)
{
	char	*new_str;
	char	*str;
	size_t	i;
	t_list	*rtn;

	i = 0;
	str = buffer;
	while (str[i])
		i++;
	new_str = (char *)malloc(sizeof(char) * i + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	rtn = (t_list *)malloc(sizeof(t_list));
	if (!rtn)
		return (free(new_str), NULL);
	(*rtn).buffer = new_str;
	(*rtn).next = NULL;
	return (rtn);
}
//check !buffer??

t_list	*lstlast0_lstback1(t_list **lst, t_list *new, int last0_back1)
{
	t_list	*current;

	if (lst == NULL)
		return (NULL);
	if (last0_back1 == 0)
	{
		if (*lst == NULL)
			return (NULL);
		current = *lst;
		while (current->next != NULL)
			current = current->next;
		return (current);
	}
	if (!new || !lst)
		return (NULL);
	if (*lst == NULL)
		*lst = new;
	else
	{
		current = *lst;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
	return (NULL);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;
	int		found_newline;

	found_newline = 0;
	if (!lst || !*lst)
		return ;
	if (lst)
	{
		while (*lst)
		{
			if (!find_newline(*lst))
				found_newline = 1;
			tmp = (*lst)->next;
			free((*lst)->buffer);
			(*lst)->buffer = 0;
			free((*lst));
			*lst = 0;
			*lst = tmp;
			if (found_newline)
				break ;
		}
	}
}
//*tmp van new node na node met \n wordt nu eerste node (*lst)
//printf("first buffer %s", tmp->buffer);

int	find_newline(t_list *node)
{
	int	i;

	i = 0;
	if (node == NULL)
		return (1);
	else
	{
		while (node->buffer[i] != '\0')
		{
			if (node->buffer[i] == '\n' || node->buffer[i] == EOF)
				return (0);
			i++;
		}
	}
	return (1);
}
