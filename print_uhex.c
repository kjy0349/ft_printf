/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:17:20 by jeykim            #+#    #+#             */
/*   Updated: 2022/09/03 13:20:05 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_udec(va_list ap)
{
	unsigned int	elem;
	int				size;

	elem = va_arg(ap, unsigned int);
	size = print_unbr(elem, 0);
	return (size + 1);
}

int	print_uhexnbr(unsigned long long elem, int size, int up)
{
	char	num;
	int		rem;

	if (elem >= 16)
		size = print_uhexnbr(elem / 16, size + 1, up);
	rem = elem % 16;
	if (rem >= 10)
	{
		rem -= 10;
		if (up == 0)
			num = 'a' + rem;
		else
			num = 'A' + rem;
	}
	else
		num = '0' + rem;
	write(1, &num, 1);
	return (size);
}

int	print_hexnbr(unsigned int elem, int size, int up)
{
	char	num;
	int		rem;

	if (elem >= 16)
		size = print_hexnbr(elem / 16, size + 1, up);
	rem = elem % 16;
	if (rem >= 10)
	{
		rem -= 10;
		if (up == 0)
			num = 'a' + rem;
		else
			num = 'A' + rem;
	}
	else
		num = '0' + rem;
	write(1, &num, 1);
	return (size);
}

int	print_hex(va_list ap, int up)
{
	unsigned int	elem;
	int				size;

	elem = va_arg(ap, unsigned int);
	size = 0;
	if (elem < 0)
	{
		write(1, "-", 1);
		elem = -elem;
		size++;
	}
	size += print_hexnbr(elem, 0, up);
	return (size + 1);
}
