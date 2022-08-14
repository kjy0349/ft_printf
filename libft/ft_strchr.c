/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:57:34 by jeykim            #+#    #+#             */
/*   Updated: 2022/04/05 14:38:06 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	*return_ptr;

	ptr = (char *)s;
	return_ptr = 0x00;
	while (*ptr != '\0')
	{
		if (*ptr == (char)c)
		{
			return_ptr = ptr;
			break ;
		}
		ptr++;
	}
	if (c == '\0' && *ptr == '\0')
		return_ptr = ptr;
	return (return_ptr);
}
