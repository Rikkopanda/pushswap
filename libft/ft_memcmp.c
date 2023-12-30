/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                      :+:         :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:43:33 by rverhoev          #+#    #+#             */
/*   Updated: 2023/10/15 12:43:34 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	size_t				i;
	const unsigned char	*bb1;
	const unsigned char	*bb2;

	bb1 = (const unsigned char *)b1;
	bb2 = (const unsigned char *)b2;
	i = 0;
	while (i < len)
	{
		if (bb1[i] != bb2[i])
			return (bb1[i] - bb2[i]);
		i++;
	}
	return (0);
}

//int main()
//{
//       int diff = memcmp("bbbbb", "bbbbb", 5);
//       printf("%d", diff);
//}