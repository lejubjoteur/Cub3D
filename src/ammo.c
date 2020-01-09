/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ammo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgimenez <qgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 11:04:30 by qgimenez          #+#    #+#             */
/*   Updated: 2020/01/08 08:49:57 by qgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		texture_ammo(t_pov *pov)
{
	char *texture;

	if (!(texture = mlx_xpm_file_to_image(pov->mlx_ptr, "texture/bullet.xpm",
		&pov->bullet.width, &pov->bullet.height)))
		return (0);
	pov->bullet.data = (unsigned char *)mlx_get_data_addr(texture,
	&pov->bullet.bit_per_pixel, &pov->bullet.size_line, &pov->bullet.endian);
	return (1);
}

void	draw_ammo2(int i, int j, t_pov *pov)
{
	while (++j < pov->f_drawend_y)
	{
		pov->f_text_y = (j - pov->f_drawstart_y) * pov->bullet.height
		/ (pov->f_drawend_y - pov->f_drawstart_y);
		if (!(((pov->bullet.data[pov->bullet.width * 4
			* pov->f_text_y + pov->f_text_x * 4 + 2]) <= 0)
			&& ((pov->bullet.data[pov->bullet.width * 4
			* pov->f_text_y + pov->f_text_x * 4 + 1]) <= 0)
			&& ((pov->bullet.data[pov->bullet.width * 4
			* pov->f_text_y + pov->f_text_x * 4]) <= 0)))
		{
			pov->img.data[(i * 4) + (j * pov->img.size_line) + 2] =
			pov->bullet.data[pov->bullet.width * 4
			* pov->f_text_y + pov->f_text_x * 4 + 2];
			pov->img.data[(i * 4) + (j * pov->img.size_line) + 1] =
			pov->bullet.data[pov->bullet.width * 4
			* pov->f_text_y + pov->f_text_x * 4 + 1];
			pov->img.data[(i * 4) + (j * pov->img.size_line)] =
			pov->bullet.data[pov->bullet.width * 4
			* pov->f_text_y + pov->f_text_x * 4];
		}
	}
}

void	draw_ammo(t_pov *pov)
{
	int i;
	int j;

	i = pov->f_drawstart_x - 1;
	while (++i < pov->f_drawend_x)
	{
		pov->f_text_x = (i - pov->f_drawstart_x) * pov->bullet.width
		/ (pov->f_drawend_x - pov->f_drawstart_x);
		j = pov->f_drawstart_y - 1;
		if (i > 0 && i < pov->res_x)
			draw_ammo2(i, j, pov);
	}
}

void	ft_ammo(t_pov *pov, int nb)
{
	pov->ammo_h = fabs((int)pov->res_y * 0.06);
	pov->ammo_w = fabs((int)pov->res_y * 0.08);
	pov->f_drawstart_y = pov->res_y * 0.95 - nb * pov->res_y / 100;
	pov->f_drawend_y = pov->f_drawstart_y + pov->ammo_h;
	pov->f_drawstart_x = pov->res_x * 0.90;
	pov->f_drawend_x = pov->f_drawstart_x + pov->ammo_w;
	draw_ammo(pov);
}
