/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 07:52:43 by rverhoev          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:22 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	free_argv(int malloced, char **argv)
{
	if (malloced)
		free_chrarr(argv);
}

int	main(int argc, char **argv)
{
	t_element	*node_a;
	int			malloced;

	malloced = 0;
	node_a = NULL;
	if (argc == 1)
		return (1);
	if (ft_strchr(argv[1], ' ') != NULL && argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		malloced = 1;
	}
	else
		argv = &argv[1];
	if (check_input(argv) == -1)
		return (free_argv(malloced, argv), 1);
	if (fill_list(&node_a, argv, chr_arr_size(argv)) == -1)
		return (ps_lstclear(&node_a), free_argv(malloced, argv), 1);
	if (node_a == NULL)
		return (ps_lstclear(&node_a), free_argv(malloced, argv), 1);
	sort_list(&node_a);
	ps_lstclear(&node_a);
	return (free_argv(malloced, argv), 0);
}

//print_lst_debug(&node_a);
//ft_putnbr_fd(node_a->stack_info->nbr_of_instructs, 1);