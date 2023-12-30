/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                     :+:         :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:43:33 by rverhoev          #+#    #+#             */
/*   Updated: 2023/10/15 12:43:34 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	c;
	char	*hay;

	i = 0;
	hay = (char *)big;
	if (little == big || ft_strlen((char *)little) == 0)
		return (hay);
	if (len == 0)
		return (0);
	while (hay[i] != '\0')
	{
		c = 0;
		if (hay[i] == little[c])
		{
			while (hay[i + c] != '\0' && little[c] != '\0'
				&& hay[i + c] == little[c] && i + c < len)
				c++;
			if (c == (size_t)ft_strlen((char *)little))
				return (&hay[i]);
		}
		i++;
	}
	return (NULL);
}
//int main()
//{
//	char *test = strnstr("haysstack" , "stack", 10);
//	printf("%s", test);
//}