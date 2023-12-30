/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                     :+:         :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:43:33 by rverhoev          #+#    #+#             */
/*   Updated: 2023/10/15 12:43:34 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*trim_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	substr = (char *)malloc(sizeof(char) * len);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len - 1)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

int	check_char_set(char chr, char *set)
{
	int	cnt;

	cnt = 0;
	while (*set != '\0')
	{
		if (*set == chr)
			cnt++;
		set++;
	}
	return (cnt);
}
// checks whole set if chr matches

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	int		begin_i;
	int		len;
	int		i;
	char	*rtn;

	begin_i = 0;
	i = 0;
	len = 0;
	s2 = (char *)s1;
	while (check_char_set(s2[begin_i], (char *)set))
		begin_i++;
	while (s2[begin_i + i] != '\0')
	{
		if (!check_char_set(s2[begin_i + i], (char *)set))
			len = i + 1;
		i++;
	}
	rtn = trim_substr(s1, begin_i, len + 1);
	return (rtn);
}
// set = ab
//			len  = 6
//				 01234 5
//				 6   10
// str =   aaaabbTEaST \0bbba // eerste niet set en laatste niet set.
// str = TEaST
//int main()
//{
//	char *test = ft_strtrim("aaaabbbbba" , "ab");
//	printf("%s", test);
//}