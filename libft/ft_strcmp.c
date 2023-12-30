/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:32:08 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/29 10:25:12 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
//	hoi
//	hoii	should return \0 - i
//compares each char, increases or decreases comp at first different one
// int main(void)
// {
// char st1 = '\200';
// char st2 = '\0';
// int test = ft_strcmp(&st1, &st2);
// printf("%d", test);
// }
