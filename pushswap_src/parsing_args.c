/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:29:52 by rverhoev          #+#    #+#             */
/*   Updated: 2023/12/20 15:30:44 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	check_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		while (argv[j])
		{
			if (!ft_strcmp(argv[i], argv[j]) && j != i)
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

//2147483647

int	check_chars(char **argv)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	j = 0;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		while (argv[i][j])
		{
			if ((num > 0 && argv[i][0] == '-')
				|| (num < 0 && argv[i][0] != '-'))
				return (-1);
			if (!ft_isdigit(argv[i][j]) && argv[i][0] != '-')
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	check_input(char **argv)
{
	if (check_duplicates(argv) == -1)
		return (write(2, "Error\n", 7), -1);
	if (check_chars(argv) == -1)
		return (write(2, "Error\n", 7), -1);
	return (0);
}
