/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:32:08 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/31 19:46:30 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strncat(char *dest, char *src, size_t nb)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < nb)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
//concatenates s2 (until n chars)onto s1 when s1 hits '\0' 
/*						
	n					0	1
	i		0	1	2	3	4	5	6
	j					0	1	2	3
	st1		h	o	i	d	a	g	\0
 | 	st2					d	a	g	\0
*/
// int main(void)
// {
// 	char st1[12] = "hoi";
// 	char st3[12] = "hoi";
// 	char st2[] = "dag";
// 	size_t copychars = 2;
// 	strncat(st1, st2, copychars);
// 	printf("%s\n", st1);
// 	ft_strncat(st3, st2, copychars);
// 	printf("%s\n", st1);
// }