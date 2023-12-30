/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                     :+:         :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:43:33 by rverhoev          #+#    #+#             */
/*   Updated: 2023/10/15 12:43:34 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	dstlen;

	dstlen = ft_strlen(dst);
	if (size <= dstlen)
		return (size + ft_strlen(src));
	j = 0;
	while (j < size - dstlen - 1 && src[j])
	{
		dst[dstlen + j] = src[j];
		j++;
	}
	dst[dstlen + j] = '\0';
	j = ft_strlen((char *)src);
	return (dstlen + ft_strlen((char *)src));
}
// appends size - strlen(dst) - 1
//int main()
//{
//	char str1[] = "test";
//	char str2[] = "123";
//	int size = strlcat(str1, str2, 9);
//	printf("%s\n", str1);
//	printf("size %d", size);
//}
//	"B\0"  = dest