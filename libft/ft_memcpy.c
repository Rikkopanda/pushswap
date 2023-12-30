/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                      :+:         :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:43:33 by rverhoev          #+#    #+#             */
/*   Updated: 2023/10/15 12:43:34 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*retptr;

	if (!dest && !src)
		return (0);
	retptr = dest;
	while (n-- > 0)
		*(unsigned char *)dest++ = *(unsigned char *)src++;
	return (retptr);
}
//make use of restrict still

//int main()
//{
//	char src[] = "yeeahboii";
//	int dst[4 * sizeof(int)];
//	int test[4] = {2147483647 ,2147483647 ,2147483647 ,2147483647 };
//	int *ptr = ft_memcpy(dst, test, 4 * sizeof(int));
//	int i = 0;
//	while(i < 4)
//	{
//		printf("%i\n", dst[i]);
//		i++;
//	}
//}