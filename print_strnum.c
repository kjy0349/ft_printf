/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:16:20 by jeykim            #+#    #+#             */
/*   Updated: 2022/09/03 13:19:53 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list ap)
{
	char	elem;

	elem = va_arg(ap, int);
	write(1, &elem, 1);
	return (1);
}

int	print_str(va_list ap)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(ap, char *);
	if (str == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &(str[i]), 1);
		i++;
	}
	return (i);
}

int	print_unbr(unsigned int elem, int size)
{
	char	num;

	if (elem >= 10)
		size = print_unbr(elem / 10, size + 1);
	num = (elem % 10) + '0';
	write(1, &num, 1);
	return (size);
}

int	print_nbr(long elem, int size)
{
	char	num;

	if (elem >= 10)
		size = print_nbr(elem / 10, size + 1);
	num = (elem % 10) + '0';
	write(1, &num, 1);
	return (size);
}

int	print_dec(va_list ap)
{
	long	elem;
	int		size;

	elem = va_arg(ap, int);
	size = 0;
	if (elem < 0)
	{
		write(1, "-", 1);
		elem = -elem;
		size++;
	}
	size += print_nbr(elem, 0);
	return (size + 1);
}
