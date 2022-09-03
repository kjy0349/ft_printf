/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:33:04 by jeyoung           #+#    #+#             */
/*   Updated: 2022/09/03 12:56:29 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		print_pointer(va_list ap);
int		print_per(void);
int		branch_args(const char *format, int idx, va_list ap);
int		print_udec(va_list ap);
int		print_hexnbr(unsigned int elem, int size, int up);
int		print_uhexnbr(unsigned long long elem, int size, int up);
int		print_hex(va_list ap, int up);
int		print_char(va_list ap);
int		print_str(va_list ap);
int		print_nbr(long elem, int size);
int		print_dec(va_list ap);
int		print_unbr(unsigned int elem, int size);

#endif