/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgimenez <qgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:59:48 by qgimenez          #+#    #+#             */
/*   Updated: 2020/01/08 08:51:48 by qgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	order_sprite(t_pov *pov)
{
	int i;

	i = -1;
	while (++i < pov->nb_sprite)
	{
		pov->sprite_order[i] = i;
		pov->sprite_dist[i] = ((pov->player_x - pov->spr[i].x)
		* (pov->player_x - pov->spr[i].x) + ((pov->player_y - pov->spr[i].y)
		* (pov->player_y - pov->spr[i].y)));
	}
	comb_sort(pov);
}

void	draw_sprite2(int d, int i, int j, t_pov *pov)
{
	while (++j < pov->s_drawend_y)
	{
		d = j * 2 - pov->res_y + pov->sprite_h;
		if ((pov->s_text_y = d * pov->sprite.height
			/ pov->sprite_h / 2) < 0)
			pov->s_text_y = 0;
		if (!(((pov->sprite.data[pov->sprite.width * 4 * pov->s_text_y
			+ pov->s_text_x * 4 + 2]) <= 0)
			&& ((pov->sprite.data[pov->sprite.width * 4 * pov->s_text_y
			+ pov->s_text_x * 4 + 1]) <= 0)
			&& ((pov->sprite.data[pov->sprite.width * 4 * pov->s_text_y
			+ pov->s_text_x * 4]) <= 0)))
		{
			pov->img.data[(i * 4) + (j * pov->img.size_line) + 2] =
			pov->sprite.data[pov->sprite.width * 4
			* pov->s_text_y + pov->s_text_x * 4 + 2];
			pov->img.data[(i * 4) + (j * pov->img.size_line) + 1] =
			pov->sprite.data[pov->sprite.width * 4
			* pov->s_text_y + pov->s_text_x * 4 + 1];
			pov->img.data[(i * 4) + (j * pov->img.size_line)] =
			pov->sprite.data[pov->sprite.width * 4
			* pov->s_text_y + pov->s_text_x * 4];
		}
	}
}

void	draw_sprite(t_pov *pov, float form_y)
{
	int i;
	int j;
	int d;

	d = 0;
	i = pov->s_drawstart_x - 1;
	while (++i < pov->s_drawend_x)
	{
		pov->s_text_x = (int)(2 * (i - (-pov->sprite_w / 2
		+ pov->sprite_screen_x)) * pov->sprite.width / pov->sprite_w) / 2;
		j = pov->s_drawstart_y - 1;
		if (form_y > 0 && form_y < pov->z_buffer[i] && i > 0 && i < pov->res_x)
			draw_sprite2(d, i, j, pov);
	}
}

void	height_sprite(t_pov *pov, float form_y)
{
	pov->sprite_h = fabs((int)pov->res_y / form_y);
	pov->s_drawstart_y = -pov->sprite_h / 2 + pov->res_y / 2;
	if (pov->s_drawstart_y < 0)
		pov->s_drawstart_y = 0;
	pov->s_drawend_y = pov->sprite_h / 2 + pov->res_y / 2;
	if (pov->s_drawend_y >= pov->res_y)
		pov->s_drawend_y = pov->res_y - 1;
	if (pov->s_drawstart_y > pov->res_y)
		pov->s_drawend_y = pov->res_y - 1;
	pov->sprite_w = fabs((int)pov->res_y / form_y);
	pov->s_drawstart_x = -pov->sprite_w / 2 + pov->sprite_screen_x;
	if (pov->s_drawstart_x < 0)
		pov->s_drawstart_x = 0;
	pov->s_drawend_x = pov->sprite_w / 2 + pov->sprite_screen_x;
	if (pov->s_drawend_x >= pov->res_x)
		pov->s_drawend_x = pov->res_x - 1;
	if (pov->s_drawstart_x > pov->res_x)
		pov->s_drawend_x = pov->res_x - 1;
	draw_sprite(pov, form_y);
}

void	ft_sprite(t_pov *pov)
{
	float	invet;
	float	form_x;
	float	form_y;
	int		i;

	i = -1;
	count_sprite(pov);
	order_sprite(pov);
	while (++i < pov->nb_sprite)
	{
		pov->sprite_x = 0.5 + pov->spr[pov->sprite_order[i]].x - pov->player_x;
		pov->sprite_y = 0.5 + pov->spr[pov->sprite_order[i]].y - pov->player_y;
		invet = 1.0 / (pov->plan_x * pov->dir_y - pov->dir_x * pov->plan_y);
		form_x = invet * (pov->dir_y * pov->sprite_x
		- pov->dir_x * pov->sprite_y);
		form_y = invet * (-pov->plan_y * pov->sprite_x
		+ pov->plan_x * pov->sprite_y);
		pov->sprite_screen_x = (int)(pov->res_x / 2) * (1 + form_x / form_y);
		height_sprite(pov, form_y);
	}
}
