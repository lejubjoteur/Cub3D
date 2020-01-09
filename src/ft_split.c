/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgimenez <qgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:41:26 by qgimenez          #+#    #+#             */
/*   Updated: 2020/01/08 08:51:05 by qgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int		count_size(char const *s, char c)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (*s)
	{
		if (*s != c && !n)
		{
			n++;
			i++;
		}
		if (*s == c)
			n = 0;
		s++;
	}
	return (i);
}

static int		add_word(char **dst, char const *curseur, char const *s, int j)
{
	int	i;

	i = 0;
	if (!(dst[j] = malloc(sizeof(char) * (curseur - s + 1))))
	{
		while (j-- > 0)
			free(dst[j]);
		free(dst);
		return (0);
	}
	while (s < curseur)
		dst[j][i++] = *s++;
	dst[j][i] = '\0';
	return (1);
}

char			**ft_split(char const *s, char c)
{
	int			j;
	char		**dst;
	char const	*curseur;

	if (!s)
		return (NULL);
	curseur = s;
	j = 0;
	if (!(dst = malloc(sizeof(char *) * (count_size(s, c) + 1))))
		return (NULL);
	dst[count_size(s, c)] = 0;
	while (*s)
	{
		while (*curseur != c && *curseur)
			curseur++;
		if (curseur - s > 0)
		{
			if (add_word(dst, curseur, s, j++) == 0)
				return (NULL);
			s = curseur;
		}
		if (*s++ == 0 || !curseur++)
			break ;
	}
	return (dst);
}
