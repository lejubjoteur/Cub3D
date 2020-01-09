/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgimenez <qgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 13:34:37 by qgimenez          #+#    #+#             */
/*   Updated: 2020/01/08 08:51:58 by qgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_weapon2(t_pov *pov)
{
	pov->tab[16] = "texture/weapon/weapon16.xpm";
	pov->tab[17] = "texture/weapon/weapon17.xpm";
	pov->tab[18] = "texture/weapon/weapon18.xpm";
	pov->tab[19] = "texture/weapon/weapon19.xpm";
	pov->tab[20] = "texture/weapon/weapon20.xpm";
	pov->tab[21] = "texture/weapon/weapon21.xpm";
	pov->tab[22] = "texture/weapon/weapon22.xpm";
	pov->tab[23] = "texture/weapon/weapon23.xpm";
	pov->tab[24] = "texture/weapon/weapon24.xpm";
	pov->tab[25] = "texture/weapon/weapon25.xpm";
	pov->tab[26] = "texture/weapon/weapon26.xpm";
	pov->tab[27] = "texture/weapon/weapon27.xpm";
	pov->tab[28] = "texture/weapon/weapon28.xpm";
	pov->tab[29] = "texture/weapon/weapon29.xpm";
	pov->tab[30] = "texture/weapon/weapon30.xpm";
	pov->tab[31] = "texture/weapon/weapon31.xpm";
	pov->tab[32] = "texture/weapon/weapon32.xpm";
	pov->tab[33] = "texture/weapon/weapon33.xpm";
	pov->tab[34] = "texture/weapon/weapon34.xpm";
	pov->tab[35] = "texture/weapon/weapon35.xpm";
	pov->tab[36] = "texture/weapon/weapon36.xpm";
	pov->tab[37] = "texture/weapon/weapon37.xpm";
}

void	init_weapon(t_pov *pov)
{
	pov->tab[0] = "texture/weapon/weapon0.xpm";
	pov->tab[1] = "texture/weapon/weapon1.xpm";
	pov->tab[2] = "texture/weapon/weapon2.xpm";
	pov->tab[3] = "texture/weapon/weapon3.xpm";
	pov->tab[4] = "texture/weapon/weapon4.xpm";
	pov->tab[5] = "texture/weapon/weapon5.xpm";
	pov->tab[6] = "texture/weapon/weapon6.xpm";
	pov->tab[7] = "texture/weapon/weapon7.xpm";
	pov->tab[8] = "texture/weapon/weapon8.xpm";
	pov->tab[9] = "texture/weapon/weapon9.xpm";
	pov->tab[10] = "texture/weapon/weapon10.xpm";
	pov->tab[11] = "texture/weapon/weapon11.xpm";
	pov->tab[12] = "texture/weapon/weapon12.xpm";
	pov->tab[13] = "texture/weapon/weapon13.xpm";
	pov->tab[14] = "texture/weapon/weapon14.xpm";
	pov->tab[15] = "texture/weapon/weapon15.xpm";
	init_weapon2(pov);
}

void	draw_weapon2(int i, int j, t_pov *pov)
{
	while (++j < pov->w_drawend_y)
	{
		pov->w_text_y = (j - pov->w_drawstart_y) * pov->weapon.height
		/ (pov->w_drawend_y - pov->w_drawstart_y);
		if (!(((pov->weapon.data[pov->weapon.width * 4 * pov->w_text_y
			+ pov->w_text_x * 4 + 2]) <= 0)
			&& ((pov->weapon.data[pov->weapon.width * 4 * pov->w_text_y
			+ pov->w_text_x * 4 + 1]) <= 0)
			&& ((pov->weapon.data[pov->weapon.width * 4 * pov->w_text_y
			+ pov->w_text_x * 4]) <= 0)))
		{
			pov->img.data[(i * 4) + (j * pov->img.size_line) + 2] =
			pov->weapon.data[pov->weapon.width * 4 * pov->w_text_y
			+ pov->w_text_x * 4 + 2];
			pov->img.data[(i * 4) + (j * pov->img.size_line) + 1] =
			pov->weapon.data[pov->weapon.width * 4 * pov->w_text_y
			+ pov->w_text_x * 4 + 1];
			pov->img.data[(i * 4) + (j * pov->img.size_line)] =
			pov->weapon.data[pov->weapon.width * 4 * pov->w_text_y
			+ pov->w_text_x * 4];
		}
	}
}

void	draw_weapon(t_pov *pov)
{
	int i;
	int j;

	i = pov->w_drawstart_x - 1;
	while (++i < pov->w_drawend_x)
	{
		pov->w_text_x = (i - pov->w_drawstart_x) * pov->weapon.width
		/ (pov->w_drawend_x - pov->w_drawstart_x);
		j = pov->w_drawstart_y - 1;
		if (i > 0 && i < pov->res_x)
			draw_weapon2(i, j, pov);
	}
}

void	ft_weapon(t_pov *pov)
{
	pov->weapon_h = fabs((int)pov->res_y * 0.45);
	pov->weapon_w = fabs((int)pov->res_y * 0.45);
	pov->w_drawstart_y = pov->res_y * 0.55;
	pov->w_drawend_y = pov->w_drawstart_y + pov->weapon_h;
	pov->w_drawstart_x = pov->res_x * 0.5;
	pov->w_drawend_x = pov->w_drawstart_x + pov->weapon_w;
	draw_weapon(pov);
}
