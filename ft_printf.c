/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:31:37 by jeyoung           #+#    #+#             */
/*   Updated: 2022/08/16 15:55:16 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_args(const char *format, int idx)
{
	if ()
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
			idx = function(format, idx);
		else
			len += write(1, &(format[idx]), 1);
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
