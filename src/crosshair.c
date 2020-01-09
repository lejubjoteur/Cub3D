/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crosshair.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgimenez <qgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 13:49:14 by qgimenez          #+#    #+#             */
/*   Updated: 2020/01/08 08:50:21 by qgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		texture_crosshair(t_pov *pov)
{
	char *texture;

	if (!(texture = mlx_xpm_file_to_image(pov->mlx_ptr, "texture/crosshair.xpm",
		&pov->crosshair.width, &pov->crosshair.height)))
		return (0);
	pov->crosshair.data = (unsigned char *)mlx_get_data_addr(texture,
	&pov->crosshair.bit_per_pixel, &pov->crosshair.size_line,
	&pov->crosshair.endian);
	return (texture_fire(pov));
}

void	draw_crosshair2(int i, int j, t_pov *pov)
{
	while (++j < pov->c_drawend_y)
	{
		pov->c_text_y = (j - pov->c_drawstart_y) * pov->crosshair.height
		/ (pov->c_drawend_y - pov->c_drawstart_y);
		if (!(((pov->crosshair.data[pov->crosshair.width * 4
			* pov->c_text_y + pov->c_text_x * 4 + 2]) <= 0)
			&& ((pov->crosshair.data[pov->crosshair.width * 4
			* pov->c_text_y + pov->c_text_x * 4 + 1]) <= 0)
			&& ((pov->crosshair.data[pov->crosshair.width * 4
			* pov->c_text_y + pov->c_text_x * 4]) <= 0)))
		{
			pov->img.data[(i * 4) + (j * pov->img.size_line) + 2] =
			pov->crosshair.data[pov->crosshair.width * 4 *
			pov->c_text_y + pov->c_text_x * 4 + 2];
			pov->img.data[(i * 4) + (j * pov->img.size_line) + 1] =
			pov->crosshair.data[pov->crosshair.width * 4 *
			pov->c_text_y + pov->c_text_x * 4 + 1];
			pov->img.data[(i * 4) + (j * pov->img.size_line)] =
			pov->crosshair.data[pov->crosshair.width * 4 *
			pov->c_text_y + pov->c_text_x * 4];
		}
	}
}

void	draw_crosshair(t_pov *pov)
{
	int i;
	int j;

	i = pov->c_drawstart_x - 1;
	while (++i < pov->c_drawend_x)
	{
		pov->c_text_x = (i - pov->c_drawstart_x) * pov->crosshair.width
		/ (pov->c_drawend_x - pov->c_drawstart_x);
		j = pov->c_drawstart_y - 1;
		if (i > 0 && i < pov->res_x)
			draw_crosshair2(i, j, pov);
	}
}

void	ft_crosshair(t_pov *pov)
{
	pov->crosshair_h = fabs((int)pov->res_y * 0.07);
	pov->crosshair_w = fabs((int)pov->res_y * 0.07);
	pov->c_drawstart_y = pov->res_y * 0.46;
	pov->c_drawend_y = pov->c_drawstart_y + pov->crosshair_h;
	pov->c_drawstart_x = pov->res_x * 0.5;
	pov->c_drawend_x = pov->c_drawstart_x + pov->crosshair_w;
	draw_crosshair(pov);
}
