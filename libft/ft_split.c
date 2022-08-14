/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:33:46 by jeykim            #+#    #+#             */
/*   Updated: 2022/04/12 15:35:38 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_spcount(char const *s, char c)
{
	int	sp_count;

	sp_count = 0;
	while (*s != '\0')
	{
		while (*s != c && *s != '\0')
			s++;
		sp_count++;
		while (*s == c && *s != '\0')
			s++;
	}
	return (sp_count);
}

static int	get_str_length(char const *s, char c)
{
	int			i;
	int			length;

	i = 0;
	length = 0;
	while (s[i] != c && s[i] != '\0')
	{
		length++;
		i++;
	}
	return (length);
}

static char const	*make_str(char **ptr, char const *s, int length)
{
	int	j;

	j = 0;
	while (j < length)
	{
		(*ptr)[j] = *s;
		s++;
		j++;
	}
	(*ptr)[j] = '\0';
	return (s);
}

static void	*free_all(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	ptr = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**ptr;
	int				length;
	char			**return_ptr;

	if (!s)
		return (NULL);
	while (*s == c && *s != '\0')
		s++;
	ptr = (char **)malloc(sizeof(char *) * (get_spcount(s, c) + 1));
	if (!ptr)
		return (NULL);
	return_ptr = ptr;
	return_ptr[get_spcount(s, c)] = 0;
	while (*s)
	{
		length = get_str_length(s, c);
		*ptr = (char *)malloc(sizeof(char) * length + 1);
		if (!ptr)
			return (free_all(return_ptr));
		s = make_str(ptr, s, length);
		while (*s == c && *s != '\0')
			s++;
		ptr++;
	}
	return (return_ptr);
}
