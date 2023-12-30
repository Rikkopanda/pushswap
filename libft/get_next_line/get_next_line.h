/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:17:33 by rverhoev          #+#    #+#             */
/*   Updated: 2023/10/31 10:17:36 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include "stdlib.h"
# include "stdio.h"
# include "unistd.h"

typedef struct list
{
	char		*buffer;
	struct list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*create_list(int fd, t_list **list);
char	*make_next_line(t_list **list, int size);
void	create_leftover(t_list **list, char *left_over_str);
char	*ret_next_line(t_list **list);

char	*ft_strchr(const char *s, int c);
t_list	*ft_lstnew_strdup(void *buffer);
void	ft_lstclear(t_list **lst);
t_list	*lstlast0_lstback1(t_list **lst, t_list *new, int last0_back1);
int		find_newline(t_list *node);

#endif
