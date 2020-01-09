/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgimenez <qgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 13:37:23 by qgimenez          #+#    #+#             */
/*   Updated: 2020/01/08 15:38:58 by qgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		texture_sprite(t_pov *pov, t_parse *config)
{
	char *texture;

	if (!(texture = mlx_xpm_file_to_image(pov->mlx_ptr, config->s,
		&pov->sprite.width, &pov->sprite.height)))
		return (0);
	pov->sprite.data = (unsigned char *)mlx_get_data_addr(texture,
	&pov->sprite.bit_per_pixel, &pov->sprite.size_line, &pov->sprite.endian);
	reset_mem(config);
	return (texture_crosshair(pov));
}

void	swap_sprite(int i, int j, t_pov *pov)
{
	int		tmp1;
	float	tmp2;

	tmp1 = pov->sprite_order[i];
	pov->sprite_order[i] = pov->sprite_order[j];
	pov->sprite_order[j] = tmp1;
	tmp2 = pov->sprite_dist[i];
	pov->sprite_dist[i] = pov->sprite_dist[j];
	pov->sprite_dist[j] = tmp2;
}

void	comb_sort(t_pov *pov)
{
	int gap;
	int	swap;
	int t[2];

	gap = pov->nb_sprite;
	swap = 0;
	while (gap > 1 || swap)
	{
		gap = (gap * 10) / 13;
		if (gap == 9 || gap == 10)
			gap = 11;
		if (gap < 1)
			gap = 1;
		swap = 0;
		t[0] = -1;
		while (++t[0] < pov->nb_sprite - gap)
		{
			t[1] = t[0] + gap;
			if (pov->sprite_dist[t[0]] < pov->sprite_dist[t[1]])
			{
				swap_sprite(t[0], t[1], pov);
				swap = 1;
			}
		}
	}
}
