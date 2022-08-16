/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:31:37 by jeyoung           #+#    #+#             */
/*   Updated: 2022/08/16 16:18:43 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(const char *format, int idx, va_list ap)
{
	char	elem;

	elem = va_arg(ap, char);
	write(1, &elem, 1);
	return (1);
}

void	print_str(const char *format, int idx, va_list ap)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(ap, char *);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	print_dec(const char *format, int idx, va_list ap)
{
	long	elem;
	int		size;

	elem = va_arg(ap, long);
	size = 0;
	if (elem < 0)
	{
		write(1, "-", 1);
		elem = -elem;
		size++;
	}
	print_nbr(elem, &size);
	return (size);
}

void	print_nbr(long elem, int *size)
{
	char	num;

	if (elem >= 10)
		print_nbr(elem % 10, size);
	num = (elem % 10) + '0';
	write(1, &num, 1);
	*size++;
}

int	print_pointer(va_list ap)
{
	long long	num;

	num = va_arg(ap, void *);
}

int	print_udec(va_list ap)
{
	unsigned int	elem;
	int				size;

	elem = va_arg(ap, unsigned int);
	print_nbr(elem, &size);
	return (size);
}

int	branch_args(const char *format, int idx, va_list ap)
{
	char	elem;
	int		new_idx;

	elem = format[idx + 1];
	if (elem == 'c')
		new_idx = print_char(format, idx, ap);
	if (elem == 's')
		new_idx = printf_str(format, idx, ap);
	if (elem == 'p')
		new_idx = print_pointer(ap);
	if (elem == 'd')
		new_idx = print_dec(format, idx, ap);
	if (elem == 'i')
		new_idx = print_dec(format, idx, ap);
	if (elem == 'u')
		new_idx = print_udec(ap);
	if (elem == 'x')
	if (elem == 'X')
	if (elem == '%')
	return (idx + new_idx);
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
			idx = branch_args(format, idx, ap);
		else
			len += write(1, &format[idx], 1);
		va_arg(ap, char);
		format++;
	}
	va_end(ap);
}

#include <stdio.h>
int	main()
{
	int	*a;

	printf("%c %s %p %d %i %u %.2x %X %%", 'c', "clear", a, 42, 42, -42, 42, 42);
}
