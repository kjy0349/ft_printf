/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:00:41 by jeykim            #+#    #+#             */
/*   Updated: 2022/04/05 14:30:51 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	if (n > 0)
	{
		while (i < n - 1 && s1[i] != '\0' && s2[i] != '\0')
		{
			if (s1[i] != s2[i])
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
			i++;
		}
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
