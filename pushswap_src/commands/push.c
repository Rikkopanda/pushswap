/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 07:52:03 by rverhoev          #+#    #+#             */
/*   Updated: 2023/12/20 16:34:02 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

static t_bool	dest_is_null(t_element **src, t_element **dest, t_element *tmp)
{
	if (*dest == NULL)
	{
		tmp = *src;
		*src = (*src)->element_down;
		*dest = tmp;
		(*dest)->element_down = NULL;
		(*dest)->up = NULL;
		(*src)->up = NULL;
		return (1);
	}
	return (0);
}

static t_bool	src_is_single(t_element **src, t_element **dest)
{
	if ((*src)->element_down == NULL)
	{
		(*src)->element_down = *dest;
		*dest = *src;
		*src = NULL;
		return (1);
	}
	return (0);
}

static void	push(t_element **src, t_element **dest)
{
	t_element	*tmp;

	if (*src == NULL)
		return ;
	if (src_is_single(src, dest))
		return ;
	tmp = (*src)->element_down;
	if (dest_is_null(src, dest, tmp))
		return ;
	(*src)->element_down = *dest;
	*dest = *src;
	(*dest)->up = NULL;
	(*dest)->element_down->up = *dest;
	*src = tmp;
	(*src)->up = NULL;
}

/* do_pa:
*	Pushes the top t_element of stack b to the top of stack a.
*	Prints "pa" to the standard output.
*/
void	do_pa(t_element **src_stack, t_element **dst_stack, t_bool print)
{
	(*src_stack)->stack_info->nbr_of_instructs++;
	push(src_stack, dst_stack);
	if (print)
		ft_putstr_fd("pa\n", 1);
}

/* do_pb:
*	Pushes the top t_element of stack a to the top of stack b.
*	Prints "pb" to the standard output.
*/
void	do_pb(t_element **src_stack, t_element **dst_stack, t_bool print)
{
	(*src_stack)->stack_info->nbr_of_instructs++;
	push(src_stack, dst_stack);
	if (print)
		ft_putstr_fd("pb\n", 1);
}
