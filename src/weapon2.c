/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgimenez <qgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 14:17:31 by qgimenez          #+#    #+#             */
/*   Updated: 2020/01/08 08:52:03 by qgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		texture_hud(t_pov *pov, char *path)
{
	char *texture;

	if (!(texture = mlx_xpm_file_to_image(pov->mlx_ptr,
		path, &pov->weapon.width, &pov->weapon.height)))
		return (0);
	pov->weapon.data = (unsigned char *)mlx_get_data_addr(texture,
	&pov->weapon.bit_per_pixel, &pov->weapon.size_line, &pov->weapon.endian);
	return (1);
}
