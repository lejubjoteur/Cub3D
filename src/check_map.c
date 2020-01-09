/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgimenez <qgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 13:55:11 by qgimenez          #+#    #+#             */
/*   Updated: 2020/01/08 12:50:15 by qgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		check_map2(int len, int nbline, char *map)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (map[i])
	{
		if (map[i] == '\n')
			j++;
		else if (map[i] != '1' && (j == 1 || j == nbline - 1
			|| i % (len + 1) == 0 || i % len - j + 2 == 0))
			return (ft_error(2));
		i++;
	}
	return (1);
}

int		check_map(t_parse *conf, char *map)
{
	conf->nbline = 1;
	while (map[conf->i])
	{
		if (ft_memchr("012NSEW", map[conf->i], 7) > 0)
			conf->len++;
		else if (!ft_memchr("012NSEW\n", map[conf->i], 8))
			return (ft_error(4));
		if (map[conf->i] == '\n' && conf->nbline == 1)
			conf->first_len = conf->len;
		if (map[conf->i] == '\n' && map[conf->i + 1] != '\n')
		{
			if (conf->len != conf->first_len)
				return (ft_error(3));
			conf->nbline++;
			conf->len = 0;
		}
		if (ft_memchr("NSEW", map[conf->i], 4) > 0)
			conf->bool++;
		conf->i++;
	}
	if (conf->bool == 0 || conf->bool > 1)
		return (ft_error(5));
	return (check_map2(conf->first_len, conf->nbline, map));
}

void	p_direction(t_parse *conf, char **map, int i, int j)
{
	conf->pos_x = j;
	conf->pos_y = i;
	if (map[i][j] == 'N')
	{
		conf->dir_y = -1;
		conf->plan_x = 0.66;
	}
	if (map[i][j] == 'S')
	{
		conf->dir_y = 1;
		conf->plan_x = -0.66;
	}
	if (map[i][j] == 'E')
	{
		conf->dir_x = 1;
		conf->plan_y = 0.66;
	}
	if (map[i][j] == 'W')
	{
		conf->dir_x = -1;
		conf->plan_y = -0.66;
	}
}
