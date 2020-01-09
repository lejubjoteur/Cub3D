/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgimenez <qgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:12:18 by qgimenez          #+#    #+#             */
/*   Updated: 2020/01/08 08:52:15 by qgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	texture_ciel(int i, int j, t_pov *arg)
{
	arg->img.data[(i * 4) + (j * arg->img.size_line) + 2] = arg->sky.red;
	arg->img.data[(i * 4) + (j * arg->img.size_line) + 1] = arg->sky.green;
	arg->img.data[(i * 4) + (j * arg->img.size_line)] = arg->sky.blue;
}

void	texture_mur(int i, int j, t_txt *text, t_pov *arg)
{
	text->x = (text->wall_x * (float)arg->txt_print.width);
	if (!arg->side && arg->raydir_x < 0)
		text->x = arg->txt_print.width - text->x - 1;
	if (arg->side == 1 && arg->raydir_y > 0)
		text->x = arg->txt_print.width - text->x - 1;
	if (arg->line_h == 0)
		arg->line_h = 1;
	text->d = j * 2 - arg->res_y + arg->line_h;
	if ((text->y = ((text->d * arg->txt_print.height) / arg->line_h) / 2) < 0)
		text->y = 0;
	arg->img.data[(i * 4) + (j * arg->img.size_line) + 2] =
	arg->txt_print.data[arg->txt_print.width * 4 * text->y + text->x * 4 + 2];
	arg->img.data[(i * 4) + (j * arg->img.size_line) + 1] =
	arg->txt_print.data[arg->txt_print.width * 4 * text->y + text->x * 4 + 1];
	arg->img.data[(i * 4) + (j * arg->img.size_line)] =
	arg->txt_print.data[arg->txt_print.width * 4 * text->y + text->x * 4];
}

void	texture_sol(int i, int j, t_pov *arg)
{
	arg->img.data[(i * 4) + (j * arg->img.size_line) + 2] = arg->floor.red;
	arg->img.data[(i * 4) + (j * arg->img.size_line) + 1] = arg->floor.green;
	arg->img.data[(i * 4) + (j * arg->img.size_line)] = arg->floor.blue;
}
