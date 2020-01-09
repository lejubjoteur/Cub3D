/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgimenez <qgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:41:16 by qgimenez          #+#    #+#             */
/*   Updated: 2020/01/08 08:51:36 by qgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move(float speed, t_pov *new)
{
	if ((new->map[(int)new->player_y][(int)(new->player_x
		+ (new->dir_x * speed))] != '1')
		&& (new->map[(int)new->player_y][(int)(new->player_x
		+ (new->dir_x * speed))] != '2'))
		new->player_x += new->dir_x * speed;
	if ((new->map[(int)(new->player_y + (new->dir_y
		* speed))][(int)new->player_x] != '1')
		&& (new->map[(int)(new->player_y + (new->dir_y
		* speed))][(int)new->player_x] != '2'))
		new->player_y += new->dir_y * speed;
}

void	strafe(float speed, t_pov *new)
{
	if ((new->map[(int)new->player_y][(int)(new->player_x
		+ (new->plan_x * speed))] != '1')
		&& (new->map[(int)new->player_y][(int)(new->player_x
		+ (new->plan_x * speed))] != '2'))
		new->player_x += new->plan_x * speed;
	if ((new->map[(int)(new->player_y + (new->plan_y
		* speed))][(int)new->player_x] != '1')
		&& (new->map[(int)(new->player_y + (new->plan_y
		* speed))][(int)new->player_x] != '2'))
		new->player_y += new->plan_y * speed;
}

void	rotation_pov(float rot, t_pov *new)
{
	new->old_dir_x = new->dir_x;
	new->dir_x = new->dir_x * cos(rot) - new->dir_y * sin(rot);
	new->dir_y = new->old_dir_x * sin(rot) + new->dir_y * cos(rot);
	new->old_plan_x = new->plan_x;
	new->plan_x = new->plan_x * cos(rot) - new->plan_y * sin(rot);
	new->plan_y = new->old_plan_x * sin(rot) + new->plan_y * cos(rot);
}

void	mouse_rotation(float rot, t_pov *pov)
{
	pov->old_dir_x = pov->dir_x;
	pov->dir_x = pov->dir_x * cos(rot * pov->mouv_x / 300)
	- pov->dir_y * sin(rot * pov->mouv_x / 300);
	pov->dir_y = pov->old_dir_x * sin(rot * pov->mouv_x / 300)
	+ pov->dir_y * cos(rot * pov->mouv_x / 300);
	pov->old_plan_x = pov->plan_x;
	pov->plan_x = pov->plan_x * cos(rot * pov->mouv_x / 300)
	- pov->plan_y * sin(rot * pov->mouv_x / 300);
	pov->plan_y = pov->old_plan_x * sin(rot * pov->mouv_x / 300)
	+ pov->plan_y * cos(rot * pov->mouv_x / 300);
}
