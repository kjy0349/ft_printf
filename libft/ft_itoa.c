/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoung <jeyoung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:50:13 by jeykim            #+#    #+#             */
/*   Updated: 2022/08/14 16:07:10 by jeyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_length(long n, int *sign)
{
	int		length;

	length = 0;
	if (n < 0)
	{
		n = -n;
		*sign = -1;
		length++;
	}
	else
		*sign = 1;
	while (n >= 10)
	{
		n /= 10;
		length++;
	}
	length++;
	return (length);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			length;
	int			sign;
	long		number;

	number = n;
	length = get_num_length(number, &sign);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	if (number < 0)
		number = -number;
	str[length] = '\0';
	length--;
	while (length > 0)
	{
		str[length] = '0' + number % 10;
		number /= 10;
		length--;
	}
	str[length] = '0' + number;
	if (sign < 0)
		str[0] = '-';
	return (str);
}
