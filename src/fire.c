/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fire.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgimenez <qgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:37:14 by qgimenez          #+#    #+#             */
/*   Updated: 2020/01/08 08:50:27 by qgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		texture_fire(t_pov *pov)
{
	char *texture;

	if (!(texture = mlx_xpm_file_to_image(pov->mlx_ptr, "texture/fire.xpm",
		&pov->fire.width, &pov->fire.height)))
		return (0);
	pov->fire.data = (unsigned char *)mlx_get_data_addr(texture,
	&pov->fire.bit_per_pixel
		, &pov->fire.size_line, &pov->fire.endian);
	return (texture_ammo(pov));
}

void	draw_fire2(int i, int j, t_pov *pov)
{
	while (++j < pov->f_drawend_y)
	{
		pov->f_text_y = (j - pov->f_drawstart_y) * pov->fire.height
		/ (pov->f_drawend_y - pov->f_drawstart_y);
		if (!(((pov->fire.data[pov->fire.width * 4
			* pov->f_text_y + pov->f_text_x * 4 + 2]) <= 0)
			&& ((pov->fire.data[pov->fire.width * 4
			* pov->f_text_y + pov->f_text_x * 4 + 1]) <= 0)
			&& ((pov->fire.data[pov->fire.width * 4
			* pov->f_text_y + pov->f_text_x * 4]) <= 0)))
		{
			pov->img.data[(i * 4) + (j * pov->img.size_line) + 2] =
			pov->fire.data[pov->fire.width * 4
			* pov->f_text_y + pov->f_text_x * 4 + 2];
			pov->img.data[(i * 4) + (j * pov->img.size_line) + 1] =
			pov->fire.data[pov->fire.width * 4
			* pov->f_text_y + pov->f_text_x * 4 + 1];
			pov->img.data[(i * 4) + (j * pov->img.size_line)] =
			pov->fire.data[pov->fire.width * 4
			* pov->f_text_y + pov->f_text_x * 4];
		}
	}
}

void	draw_fire(t_pov *pov)
{
	int i;
	int j;

	i = pov->f_drawstart_x - 1;
	while (++i < pov->f_drawend_x)
	{
		pov->f_text_x = (i - pov->f_drawstart_x) * pov->fire.width
		/ (pov->f_drawend_x - pov->f_drawstart_x);
		j = pov->f_drawstart_y - 1;
		if (i > 0 && i < pov->res_x)
			draw_fire2(i, j, pov);
	}
}

void	ft_fire(t_pov *pov)
{
	pov->ammo--;
	hit_sprite(pov);
	pov->fire_h = fabs((int)pov->res_y * 0.1);
	pov->fire_w = fabs((int)pov->res_y * 0.1);
	pov->f_drawstart_y = pov->res_y * 0.555;
	pov->f_drawend_y = pov->f_drawstart_y + pov->fire_h;
	pov->f_drawstart_x = pov->res_x * 0.525;
	pov->f_drawend_x = pov->f_drawstart_x + pov->fire_w;
	draw_fire(pov);
}
