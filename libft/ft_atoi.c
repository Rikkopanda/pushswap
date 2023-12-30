/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:43:33 by rverhoev          #+#    #+#             */
/*   Updated: 2023/10/15 12:43:34 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	min;
	int	num;

	num = 0;
	min = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		min = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + ((char)str[i] - 48);
		i++;
	}
	return (num * min);
}
//int ft_atoi(const char *nptr)
//{
//    int     flag;
//    int     num;
//    char    *p;
//    flag = 1;
//    num = 0;
//    p = (char *)nptr;
//    while (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r' 
//        || *p == '\f' || *p == '\v')
//        p++;
//    if (*p == '-')
//        flag = -1;
//    if (*p == '+' || *p == '-')
//        p++;
//    while (*p <= '9' && *p >= '0')
//    {
//        num = num * 10 + (*p - '0');
//        p++;
//    }
//    return (flag * num);
//}
