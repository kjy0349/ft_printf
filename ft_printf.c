/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:31:37 by jeyoung           #+#    #+#             */
/*   Updated: 2022/09/03 13:23:18 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(va_list ap)
{
	unsigned long long	num;
	int					size;

	num = va_arg(ap, unsigned long long);
	write(1, "0x", 2);
	size = 2;
	size += print_uhexnbr(num, 0, 0);
	return (size + 1);
}

int	print_per(void)
{
	char	elem;

	elem = '%';
	write(1, &elem, 1);
	return (1);
}

int	branch_args(const char *format, int idx, va_list ap)
{
	char	elem;
	int		new_idx;

	elem = format[idx + 1];
	new_idx = 0;
	if (elem == 'c')
		new_idx = print_char(ap);
	else if (elem == 's')
		new_idx = print_str(ap);
	else if (elem == 'p')
		new_idx = print_pointer(ap);
	else if (elem == 'd')
		new_idx = print_dec(ap);
	else if (elem == 'i')
		new_idx = print_dec(ap);
	else if (elem == 'u')
		new_idx = print_udec(ap);
	else if (elem == 'x')
		new_idx = print_hex(ap, 0);
	else if (elem == 'X')
		new_idx = print_hex(ap, 1);
	else if (elem == '%')
		new_idx = print_per();
	return (new_idx);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		idx;

	len = 0;
	idx = -1;
	va_start(ap, format);
	while (format[++idx])
	{
		if (format[idx] == '%')
		{
			len += branch_args(format, idx, ap);
			idx++;
		}
		else
			len += write(1, &format[idx], 1);
	}
	va_end(ap);
	return (len);
}
