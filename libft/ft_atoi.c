/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 00:16:12 by jeyoung           #+#    #+#             */
/*   Updated: 2022/05/10 18:08:39 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	long				return_num;

	sign = 1;
	return_num = 0;
	i = 0;
	while (str[i] == '\n' || str[i] == '\v' || str[i] == '\t' \
	|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		return_num = return_num * 10 + str[i] - '0';
		i++;
	}
	return ((int)(return_num * sign));
}
