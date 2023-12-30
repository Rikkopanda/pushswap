/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 07:52:38 by rverhoev          #+#    #+#             */
/*   Updated: 2023/12/20 16:42:29 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	fill_list(t_element **t_elementnode_a, char **chr_arr, int argc)
{
	int				i;
	struct s_stack	*new_t_element;
	t_info			*stack_data;

	stack_data = (t_info *)malloc(sizeof(t_info));
	if (!stack_data)
		return (-1);
	new_t_element = NULL;
	*t_elementnode_a = NULL;
	i = 0;
	while (i < argc)
	{
		new_t_element = ps_lstnew(ft_atoi(chr_arr[i]), stack_data);
		if (!new_t_element)
			return (ps_lstclear(t_elementnode_a), -1);
		ps_lstadd_back(t_elementnode_a, new_t_element);
		i++;
	}
	(*t_elementnode_a)->stack_info->nbr_of_instructs = 1;
	return (0);
}

struct s_stack	*ps_lstnew(int content, t_info *stack_data)
{
	t_element	*rtn;

	rtn = (struct s_stack *)malloc(sizeof(struct s_stack));
	if (!rtn)
		return (NULL);
	(*rtn).value = content;
	(*rtn).stack_info = stack_data;
	(*rtn).cheapest = FALSE;
	(*rtn).above_median = FALSE;
	(*rtn).element_down = NULL;
	(*rtn).up = NULL;
	(*rtn).target = NULL;
	return (rtn);
}

void	ps_lstadd_back(t_element **lst, struct s_stack *new)
{
	struct s_stack	*tmp;

	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		(*lst)->element_down = NULL;
	}
	else
	{
		tmp = ps_lstlast(*lst);
		ps_lstlast(*lst)->element_down = new;
		new->up = tmp;
	}
}

void	ps_lstadd_front(t_element **lst, struct s_stack *new)
{
	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		(*lst)->element_down = NULL;
		(*lst)->cheapest = TRUE;
	}
	else
	{
		new->element_down = *lst;
		*lst = new;
	}
}
