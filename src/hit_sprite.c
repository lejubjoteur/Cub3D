/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgimenez <qgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:11:18 by qgimenez          #+#    #+#             */
/*   Updated: 2020/01/08 08:51:24 by qgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	hit_sprite(t_pov *new)
{
	float	range;
	float	pos_x;
	float	pos_y;

	range = 0.1;
	while (range <= 100)
	{
		pos_x = new->player_x + (new->dir_x * range);
		pos_y = new->player_y + (new->dir_y * range);
		if ((new->map[(int)pos_y][(int)pos_x] == '2')
			|| (new->map[(int)pos_y][(int)pos_x] == '1'))
		{
			if (new->map[(int)pos_y][(int)pos_x] == '2')
			{
				new->map[(int)pos_y][(int)pos_x] = '0';
				new->kills++;
			}
			break ;
		}
		range += 0.1;
	}
}
