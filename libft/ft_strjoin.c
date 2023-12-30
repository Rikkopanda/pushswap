/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                     :+:         :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:43:33 by rverhoev          #+#    #+#             */
/*   Updated: 2023/10/15 12:43:34 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*strjoined;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	strjoined = (char *)malloc(sizeof(char)
			* (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
	if (strjoined == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		strjoined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		strjoined[j + i] = s2[j];
		j++;
	}
	strjoined[j + i] = '\0';
	return (strjoined);
}
//int main()
//{
//	char str1[] = "test";
//	char str2[] = "123";
//	char *str3;
//	str3 = ft_strjoin(str1, str2);
//	printf("%s", str3);
//	free(str3);
//}