/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:36:09 by jeykim            #+#    #+#             */
/*   Updated: 2022/04/05 13:37:39 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr_body(long n, int fd)
{
	char	c;

	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = '0' + (n % 10);
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	putnbr_body(num, fd);
}
