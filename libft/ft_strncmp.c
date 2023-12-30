/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:32:08 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/29 10:28:51 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	if (i >= n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
//compares each char, increases or decreases comp at first different one. 
// //only up to n chars.
// int main(void)
// {
// char st1[] = "Hallo1";
// char st2[] = "";
// size_t size = 7;
// int test = ft_strncmp(st1, st2, 0);
// printf("%d", test);
// }