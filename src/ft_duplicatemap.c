/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplicatemap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgimenez <qgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 10:18:04 by qgimenez          #+#    #+#             */
/*   Updated: 2020/01/09 14:22:21 by qgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_duplicatemap(t_pov *pov, char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	pov->map = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (map[i])
	{
		pov->map[i] = ft_strdup(map[i]);
		i++;
	}
	pov->map[i] = 0;
	reset_double_ptr(map);
}

char	*ft_strjoin_kifree(char *s1, char *s2)
{
	char	*dst;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	if (!(dst = malloc(sizeof(char)
		* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[++i])
		dst[i] = s1[i];
	while (s2[++j])
		dst[i++] = s2[j];
	dst[i] = '\0';
	free(s1);
	return (dst);
}
