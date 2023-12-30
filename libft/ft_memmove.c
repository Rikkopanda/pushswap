/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                     :+:         :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:43:33 by rverhoev          #+#    #+#             */
/*   Updated: 2023/10/15 12:43:34 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void			*ret_ptr;
	unsigned char	*placeholder;
	unsigned char	*dst2;
	size_t			i;

	if (ft_strlen(src) + 1 >= n)
		placeholder = (unsigned char *)malloc(sizeof(char)
				* (ft_strlen(src) + 1));
	else if (ft_strlen(src) + 1 < n)
		placeholder = (unsigned char *)malloc(sizeof(char) * n);
	dst2 = dest;
	ret_ptr = dst2;
	i = 0;
	while (i < n)
		placeholder[i++] = *(unsigned char *)src++;
	i = 0;
	while (i < n)
	{
		dst2[i] = placeholder[i];
		i++;
	}
	free(placeholder);
	placeholder = 0;
	return (ret_ptr);
}
//int main()
//{
//	char src[] = "con\0sec\0\0te\0tur";
//	char dst[] = "oke";
//	char *ptr;
//	ptr = ft_memmove(dst, src, 10);
//	int i = 0;
//	printf("%c\n", dst[5]);
//}