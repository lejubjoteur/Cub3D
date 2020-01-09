/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgimenez <qgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 11:47:49 by qgimenez          #+#    #+#             */
/*   Updated: 2020/01/08 08:50:12 by qgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		key_press(int key, t_pov *pov)
{
	if (key == 13)
		pov->ctrl.w = 1;
	if (key == 1)
		pov->ctrl.s = 1;
	if (key == 12 || key == 123)
		pov->ctrl.rot_left = 1;
	if (key == 14 || key == 124)
		pov->ctrl.rot_right = 1;
	if (key == 0)
		pov->ctrl.a = 1;
	if (key == 2)
		pov->ctrl.d = 1;
	if (key == 15 && pov->ammo < 30)
		pov->reload = 1;
	if (key == 126 && !pov->reload)
		pov->shoot = 1;
	if (key == 256)
		pov->sneak = 1;
	if (key == 48)
		pov->focus++;
	if (key == 53)
		close_window(pov);
	return (1);
}

int		key_release(int key, t_pov *pov)
{
	if (key == 13)
		pov->ctrl.w = 0;
	if (key == 1)
		pov->ctrl.s = 0;
	if (key == 12 || key == 123)
		pov->ctrl.rot_left = 0;
	if (key == 14 || key == 124)
		pov->ctrl.rot_right = 0;
	if (key == 0)
		pov->ctrl.a = 0;
	if (key == 2)
		pov->ctrl.d = 0;
	if (key == 126)
		pov->shoot = 0;
	if (key == 256)
		pov->sneak = 0;
	return (1);
}

int		mouse_press(int button, int x, int y, t_pov *pov)
{
	(void)(x + y);
	if (button == 1 && !pov->reload)
		pov->shoot = 1;
	return (1);
}

int		mouse_release(int button, int x, int y, t_pov *pov)
{
	(void)(x + y);
	if (button == 1)
		pov->shoot = 0;
	return (1);
}

int		pos_mouse(t_pov *pov)
{
	int mouse_x;
	int mouse_y;

	mouse_x = pov->res_x / 2;
	mouse_y = pov->res_y / 2;
	if (pov->focus % 2 == 0)
	{
		mlx_mouse_hide();
		mlx_mouse_get_pos(pov->win_ptr, &mouse_x, &mouse_y);
		pov->mouv_x = mouse_x - pov->res_x / 2;
		mlx_mouse_move(pov->win_ptr, pov->res_x / 2, pov->res_y / 2);
	}
	return (1);
}
