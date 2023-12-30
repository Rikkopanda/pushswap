/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 07:52:35 by rverhoev          #+#    #+#             */
/*   Updated: 2023/12/20 16:09:20 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	free_chrarr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr[i]);
	free(arr);
}

int	chr_arr_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	ps_lstsize(t_element **elements)
{
	t_element		*current;
	int				i;

	i = 0;
	if (elements == NULL)
		return (0);
	current = *elements;
	while (current != NULL)
	{
		current = current->element_down;
		i++;
	}
	return (i);
}

struct s_stack	*ps_lstlast(struct s_stack *lst)
{
	struct s_stack	*current;

	if (lst == NULL)
		return (NULL);
	current = lst;
	while (current->element_down != NULL)
	{
		current = current->element_down;
	}
	return (current);
}

struct s_stack	*ps_second_lstlast(struct s_stack *lst)
{
	struct s_stack	*current;

	if (lst == NULL)
		return (NULL);
	current = lst;
	if (current->element_down == NULL)
		return (NULL);
	while (current->element_down->element_down != NULL)
	{
		current = current->element_down;
	}
	return (current);
}
