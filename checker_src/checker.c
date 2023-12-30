/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rik <rik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:06:12 by rverhoev          #+#    #+#             */
/*   Updated: 2023/12/30 14:44:31 by rik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"
#include "../include/checker_excl.h"

char	**read_stdin(void);

int	check(t_element **node_a, t_element **node_b, char *command)
{
	if (!ft_strcmp(command, "pb\n"))
		return (do_pb(node_a, node_b, 0), PRINTBOOL_CKR);
	else if (!ft_strcmp(command, "pa\n"))
		return (do_pa(node_b, node_a, 0), PRINTBOOL_CKR);
	else if (!ft_strcmp(command, "ra\n"))
		return (do_ra(node_a, 0), PRINTBOOL_CKR);
	else if (!ft_strcmp(command, "rb\n"))
		return (do_rb(node_b, 0), PRINTBOOL_CKR);
	else if (!ft_strcmp(command, "rr\n"))
		return (do_rr(node_a, node_b, 0), PRINTBOOL_CKR);
	else if (!ft_strcmp(command, "rra\n"))
		return (do_rra(node_a, 0), PRINTBOOL_CKR);
	else if (!ft_strcmp(command, "rrb\n"))
		return (do_rrb(node_b, 0), PRINTBOOL_CKR);
	else if (!ft_strcmp(command, "rrr\n"))
		return (do_rrr(node_a, node_b, 0), PRINTBOOL_CKR);
	else if (!ft_strcmp(command, "sa\n"))
		return (do_sa(node_a, 0), PRINTBOOL_CKR);
	else if (!ft_strcmp(command, "sb\n"))
		return (do_sb(node_b, 0), PRINTBOOL_CKR);
	else if (!ft_strcmp(command, "ss\n"))
		return (do_ss(node_a, node_b, 0), PRINTBOOL_CKR);
	return (-1);
}

void	sort_checklist(t_element **node_a, char **commands)
{
	t_element	*node_b;
	int			i;

	node_b = NULL;
	i = 0;
	while (commands[i] != NULL)
	{
		check(node_a, &node_b, commands[i]);
		i++;
	}
	if (stack_sorted(*node_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

//printf("-----------------a\n");
//print_lst_debug(node_a);
//printf("-----------------b\n");
//print_lst_debug(&node_b);

char	**fetch_commands(void)
{
	char	**bufarr;

	bufarr = read_stdin();
	return (bufarr);
}

int	main(int argc, char **argv)
{
	t_element	*node_a;
	char		**commands;
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
	fill_list(&node_a, argv, chr_arr_size(argv));
	commands = fetch_commands();
	sort_checklist(&node_a, commands);
	free_argv(malloced, argv);
	free_chrarr(commands);
	ps_lstclear(&node_a);
}
