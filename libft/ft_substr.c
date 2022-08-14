/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoung <jeyoung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 01:33:35 by jeykim            #+#    #+#             */
/*   Updated: 2022/08/06 18:19:08 by jeyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_spec_length(unsigned int s_len, unsigned int start, size_t len)
{
	if (start + len > s_len)
		return (s_len - start);
	else
		return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*ptr;
	unsigned int	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
	{
		ptr = (char *)malloc(sizeof(char));
		ptr[0] = '\0';
		return (ptr);
	}
	ptr = (char *)malloc(sizeof(char) * get_spec_length(s_len, start, len) + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		ptr[i] = s[start];
		start++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
