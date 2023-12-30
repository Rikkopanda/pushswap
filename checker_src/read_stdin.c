/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:08:12 by rverhoev          #+#    #+#             */
/*   Updated: 2023/12/20 16:08:39 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/get_next_line/get_next_line.h"

char	**read_stdin(void)
{
	char	**buf;
	int		i;

	buf = malloc(sizeof(char *) * 950000);
	i = 0;
	while (1)
	{
		buf[i] = get_next_line(STDIN_FILENO);
		if (!buf[i])
			break ;
		i++;
	}
	return (buf);
}
