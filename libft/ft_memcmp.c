/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:20:27 by jeykim            #+#    #+#             */
/*   Updated: 2022/04/05 21:27:01 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	if (n > 0)
	{
		while (i < n - 1)
		{
			if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
				return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
			i++;
		}
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
