/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgimenez <qgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 11:03:10 by qgimenez          #+#    #+#             */
/*   Updated: 2020/01/08 08:52:21 by qgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_vertical_line(int i, t_pov *arg)
{
	int		j;
	t_txt	text;

	text.wall_x = arg->player_x + arg->perpwalldist * arg->raydir_x;
	if (!arg->side)
		text.wall_x = arg->player_y + arg->perpwalldist * arg->raydir_y;
	text.wall_x -= (int)(text.wall_x);
	j = -1;
	while (++j < arg->res_y)
	{
		j < arg->draw_s ? texture_ciel(i, j, arg) : 0;
		if (j >= arg->draw_s && j < arg->draw_e)
		{
			if (arg->side == 1 && arg->map_y < (int)arg->player_y)
				arg->txt_print = arg->txt_s;
			else if (arg->side == 0 && arg->map_x < (int)arg->player_x)
				arg->txt_print = arg->txt_e;
			else if (arg->side == 0)
				arg->txt_print = arg->txt_w;
			else if (arg->side == 1)
				arg->txt_print = arg->txt_n;
			texture_mur(i, j, &text, arg);
		}
		j >= arg->draw_e ? texture_sol(i, j, arg) : 0;
	}
}

void	init_calculator(int i, t_pov *new)
{
	new->camera_x = 2 * i / (float)new->res_x - 1;
	new->raydir_x = new->dir_x + new->plan_x * new->camera_x;
	new->raydir_y = new->dir_y + new->plan_y * new->camera_x;
	new->map_x = (int)new->player_x;
	new->map_y = (int)new->player_y;
	new->deltadist_x = fabs(1 / new->raydir_x);
	new->deltadist_y = fabs(1 / new->raydir_y);
	new->hit = 0;
}

void	init_calculator2(t_pov *new)
{
	if (new->raydir_x < 0)
	{
		new->step_x = -1;
		new->sidedist_x = (new->player_x - new->map_x) * new->deltadist_x;
	}
	else
	{
		new->step_x = 1;
		new->sidedist_x = (new->map_x + 1.0 - new->player_x) * new->deltadist_x;
	}
	if (new->raydir_y < 0)
	{
		new->step_y = -1;
		new->sidedist_y = (new->player_y - new->map_y) * new->deltadist_y;
	}
	else
	{
		new->step_y = 1;
		new->sidedist_y = (new->map_y + 1.0 - new->player_y) * new->deltadist_y;
	}
}

void	find_start_end(t_pov *new)
{
	if (new->side == 0)
		new->perpwalldist = (new->map_x - new->player_x +
		(1 - new->step_x) / 2) / new->raydir_x;
	else
		new->perpwalldist = (new->map_y - new->player_y +
		(1 - new->step_y) / 2) / new->raydir_y;
	new->line_h = (int)(new->res_y / new->perpwalldist);
	new->draw_s = -new->line_h / 2 + new->res_y / 2;
	if (new->draw_s < 0)
		new->draw_s = 0;
	new->draw_e = new->line_h / 2 + new->res_y / 2;
	if (new->draw_e >= new->res_y)
		new->draw_e = new->res_y - 1;
}

void	detect_wall(t_pov *new)
{
	while (new->hit == 0)
	{
		if (new->sidedist_x < new->sidedist_y)
		{
			new->sidedist_x += new->deltadist_x;
			new->map_x += new->step_x;
			new->side = 0;
		}
		else
		{
			new->sidedist_y += new->deltadist_y;
			new->map_y += new->step_y;
			new->side = 1;
		}
		if (new->map[new->map_y][new->map_x] == '1')
			new->hit = 1;
	}
}
