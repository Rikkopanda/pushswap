/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:31:54 by rverhoev          #+#    #+#             */
/*   Updated: 2023/10/05 16:31:56 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*split_substr(char const *s, unsigned int start, size_t len)
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

static int	nbr_of_words(char *s, char c)
{
	int	nbr_of_c;
	int	i;

	i = 0;
	nbr_of_c = 0;
	if (*s == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			nbr_of_c++;
		}
		else
			i++;
	}
	return (nbr_of_c);
}

static void	*free_all(char **str_arr, int i)
{
	while (i >= 0)
	{
		free(str_arr[i]);
		str_arr[i] = 0;
		i--;
	}
	free(str_arr);
	str_arr = 0;
	return (NULL);
}

static char	**splitting(char **str_arr, char *s, char c, int nbr_of)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	j = 0;
	i = 0;
	while (j < nbr_of)
	{
		while (s[i] == c)
			i++;
		while (s[i + len] != c && s[i + len] != '\0')
			len++;
		str_arr[j] = split_substr(s, i, len + 1);
		if (str_arr[j] == NULL)
			return (free_all(str_arr, nbr_of));
		i = i + len;
		len = 0;
		j++;
	}
	str_arr[nbr_of] = NULL;
	return (str_arr);
}
//printf("i = %d, len = %d\n", i, len);
//if checkchar = check if from start is not only delims
//while start-> start++ = find next non_delim(start)
//printf("in loop str_arr %d = %s \t  
//address = %p\n", j, str_arr[j], str_arr[j]);
//	0	1	2	3	
//	t	e	s	t	\0

char	**ft_split(const char *s, char c)
{
	char	**str_arr;
	int		word_cnt;

	word_cnt = (nbr_of_words((char *)s, c));
	if (!(word_cnt == 0))
	{
		str_arr = (char **)malloc(sizeof(char *) * (word_cnt + 1));
		splitting(str_arr, (char *)s, c, word_cnt);
		if (str_arr == NULL)
			return (NULL);
	}
	if (word_cnt == 0)
	{
		str_arr = (char **)malloc(sizeof(char *) * 1);
		if (str_arr == NULL)
			return (NULL);
		str_arr[0] = NULL;
	}
	return (str_arr);
}
//printf("str_arr address = %p\n", str_arr);
//printf("str_arr %d = %s\t address = %p\n", 
//word_cnt, str_arr[word_cnt], str_arr[word_cnt]);
// printf("start = %d\n", start);
// printf("len = %d\n", len);
// str_arr[j] = (char*)malloc(sizeof(char) * len);
// str_arr[j] = ft_substr(s, start, len);
// printf("%d, %s\n\n", j, str_arr[j]);
//int main()
//{
//	char **strarr;
//	char str[] = "Hello good day";
//	strarr = ft_split(str, ' ');
//	printf("%s", strarr[0]);
//}