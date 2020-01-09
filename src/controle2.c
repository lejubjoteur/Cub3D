/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controle2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgimenez <qgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 13:52:05 by qgimenez          #+#    #+#             */
/*   Updated: 2020/01/08 08:50:16 by qgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		read_key(t_pov *new)
{
	float	rot;
	float	speed;

	rot = 0.08;
	speed = 0.30;
	if (new->sneak)
		speed = 0.05;
	if (new->ctrl.w)
		move(speed, new);
	if (new->ctrl.s)
		move(-speed, new);
	if (new->ctrl.rot_left)
		rotation_pov(-rot, new);
	if (new->ctrl.rot_right)
		rotation_pov(rot, new);
	if (new->ctrl.a)
		strafe(-speed, new);
	if (new->ctrl.d)
		strafe(speed, new);
	if (new->mouv_x)
		mouse_rotation(rot, new);
	return (1);
}
