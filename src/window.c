/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgimenez <qgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 10:54:22 by qgimenez          #+#    #+#             */
/*   Updated: 2020/01/09 13:40:39 by qgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		get_texture(t_pov *pov, t_parse *conf)
{
	void *texture;

	if (!(texture = mlx_xpm_file_to_image(pov->mlx_ptr, conf->no,
		&pov->txt_n.width, &pov->txt_n.height)))
		return (0);
	pov->txt_n.data = (unsigned char *)mlx_get_data_addr(texture,
	&pov->txt_n.bit_per_pixel, &pov->txt_n.size_line, &pov->txt_n.endian);
	if (!(texture = mlx_xpm_file_to_image(pov->mlx_ptr, conf->so,
		&pov->txt_s.width, &pov->txt_s.height)))
		return (0);
	pov->txt_s.data = (unsigned char *)mlx_get_data_addr(texture,
	&pov->txt_s.bit_per_pixel, &pov->txt_s.size_line, &pov->txt_s.endian);
	if (!(texture = mlx_xpm_file_to_image(pov->mlx_ptr, conf->ea,
		&pov->txt_e.width, &pov->txt_e.height)))
		return (0);
	pov->txt_e.data = (unsigned char *)mlx_get_data_addr(texture,
	&pov->txt_e.bit_per_pixel, &pov->txt_e.size_line, &pov->txt_e.endian);
	if (!(texture = mlx_xpm_file_to_image(pov->mlx_ptr, conf->we,
		&pov->txt_w.width, &pov->txt_w.height)))
		return (0);
	pov->txt_w.data = (unsigned char *)mlx_get_data_addr(texture,
	&pov->txt_w.bit_per_pixel, &pov->txt_w.size_line, &pov->txt_w.endian);
	return (texture_sprite(pov, conf));
}

void	count_sprite(t_pov *pov)
{
	int i;
	int j;

	i = 0;
	j = 0;
	pov->nb_sprite = 0;
	while (pov->map[i])
	{
		while (pov->map[i][j])
		{
			if (pov->map[i][j] == '2')
			{
				pov->spr[pov->nb_sprite].x = j;
				pov->spr[pov->nb_sprite].y = i;
				pov->nb_sprite++;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_init_struct(t_pov *pov, t_parse *conf, char **map)
{
	ft_duplicatemap(pov, map);
	pov->player_x = conf->pos_x + 0.5;
	pov->player_y = conf->pos_y + 0.5;
	pov->dir_x = conf->dir_x;
	pov->dir_y = conf->dir_y;
	pov->plan_x = conf->plan_x;
	pov->plan_y = conf->plan_y;
	pov->res_x = conf->rendu_x;
	pov->res_y = conf->rendu_y;
	pov->sky = conf->c;
	pov->floor = conf->f;
	pov->ammo = 30;
	init_weapon(pov);
	pov->mlx_ptr = mlx_init();
	pov->win_ptr = mlx_new_window(pov->mlx_ptr,
	pov->res_x, pov->res_y, "Dust2");
	pov->img_ptr = mlx_new_image(pov->mlx_ptr, pov->res_x, pov->res_y);
	pov->img.data = (unsigned char *)mlx_get_data_addr(pov->img_ptr,
	&pov->img.bit_per_pixel, &pov->img.size_line, &pov->img.endian);
}

int		ft_init_window(t_parse *conf, char **map, int save)
{
	t_pov	pov;

	pov = (t_pov){ 0 };
	ft_init_struct(&pov, conf, map);
	if (!get_texture(&pov, conf))
		return (ft_error(7));
	if (save)
	{
		pos_calcultor(&pov);
		ft_save(&pov, "save.bmp");
	}
	else
	{
		mlx_hook(pov.win_ptr, KEYPRESS, KEYPRESSMASK, key_press, &pov);
		mlx_hook(pov.win_ptr, KEYRELEASE, KEYRELEASEMASK, key_release, &pov);
		mlx_hook(pov.win_ptr, BUTTONPRESS, BUTTONPRESSMASK, mouse_press, &pov);
		mlx_hook(pov.win_ptr, BUTTONRELEASE, BUTTONRELEASEMASK,
		mouse_release, &pov);
		mlx_hook(pov.win_ptr, DESTROYNOTIFY, STRUCTURENOTIFYMASK,
		close_window, &pov);
		mlx_loop_hook(pov.mlx_ptr, pos_calcultor, &pov);
		mlx_loop(pov.mlx_ptr);
	}
	return (0);
}
