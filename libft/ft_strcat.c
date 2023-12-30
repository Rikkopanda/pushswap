/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:32:08 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/31 20:05:46 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
//concatenates s2 onto s1 when s1 hits '\0' 
/*
	i		0	1	2	3	4	5	6
	j					0	1	2	3
	st1		h	o	i	d	a	g	\0
	st2					d	a	g	\0
*/
// int main(void)
// {
// char st1[12] = "hoi";
// char st2[] = "dag";
// //strcat(st1, st2);
// ft_strcat(st1, st2);
// printf("%s", st1);
// }