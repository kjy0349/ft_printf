/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:05:18 by jeykim            #+#    #+#             */
/*   Updated: 2022/04/05 20:27:43 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*return_ptr;

	i = 0;
	return_ptr = NULL;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
		{
			return_ptr = &(((unsigned char *)s)[i]);
			break ;
		}
		i++;
	}
	return ((void *)return_ptr);
}
