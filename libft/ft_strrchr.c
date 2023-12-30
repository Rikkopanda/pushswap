/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                     :+:         :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:43:33 by rverhoev          #+#    #+#             */
/*   Updated: 2023/10/15 12:43:34 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*s1;
	char	*lastc;

	s1 = (char *)s;
	lastc = NULL;
	i = 0;
	if (c > 256)
		c = c - 256;
	while (s1[i] != '\0')
	{
		if (s1[i] == c)
			lastc = &s1[i];
		i++;
	}
	if (s1[i] == c)
		lastc = &s1[i];
	return (lastc);
}

//int main()
//{
//	char *test = ft_strrchr("haysstacks" , 's');
//	printf("%s", test);
//}