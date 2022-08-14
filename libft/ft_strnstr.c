/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:24:41 by jeykim            #+#    #+#             */
/*   Updated: 2022/04/05 15:42:05 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		if (needle[j] == '\0')
			break ;
		if (haystack[i] == needle[j])
			j++;
		else
		{
			i -= j;
			j = 0;
		}
		i++;
	}
	if (needle[j] == '\0')
		return (&((char *)haystack)[i - j]);
	return (NULL);
}
