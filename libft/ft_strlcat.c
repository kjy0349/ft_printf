/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:56:58 by jeykim            #+#    #+#             */
/*   Updated: 2022/03/25 18:20:25 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	origin_dstlen;

	origin_dstlen = ft_strlen(dst);
	if (origin_dstlen >= dstsize)
		return (ft_strlen(src) + dstsize);
	if (dstsize > 0)
	{
		i = 0;
		j = 0;
		while (dst[i] != '\0')
			i++;
		while (i < dstsize - 1 && src[j] != '\0')
		{
			dst[i] = src[j];
			j++;
			i++;
		}
		dst[i] = '\0';
	}
	return (origin_dstlen + ft_strlen(src));
}
