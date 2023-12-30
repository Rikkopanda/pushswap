/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:32:08 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/31 20:05:46 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s1;

	s1 = (char *)s;
	i = 0;
	if (c > 256)
		c = c - 256;
	while (s1[i] != '\0')
	{
		if (s1[i] == c)
		{
			s1 = &s1[i];
			return (s1);
		}
		i++;
	}
	if (s1[i] == c)
		return (&s1[i]);
	return (NULL);
}
//int main()
//{
//	char *test = ft_strchr("haysstack" , 's');
//	printf("%s", test);
//}