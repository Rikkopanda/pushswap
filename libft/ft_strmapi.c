/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                     :+:         :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:43:33 by rverhoev          #+#    #+#             */
/*   Updated: 2023/10/15 12:43:34 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_str;

	if (!s || !f)
		return (NULL);
	i = 0;
	new_str = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1);
	while (s[i] != '\0')
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

//static char	function2(unsigned int i, char b)
//{
//	b = b + 1;
//	i = i + 1;
//	return (b);
//}
//int main()
//{
//	char str[] = "bbbbb";
//	char *str2;
//	str2 = ft_strmapi(str, function2);
//	printf("\n%s", str2);
//}
