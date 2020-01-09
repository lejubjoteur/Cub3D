/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgimenez <qgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 15:29:22 by qgimenez          #+#    #+#             */
/*   Updated: 2020/01/09 11:18:02 by qgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_info(t_pov *new)
{
	char *stat;

	mlx_put_image_to_window(new->mlx_ptr, new->win_ptr, new->img_ptr, 0, 0);
	mlx_string_put(new->mlx_ptr, new->win_ptr, new->res_x * 0.92,
		new->res_y * 0.01, 0xff4133, "42 fps");
	mlx_string_put(new->mlx_ptr, new->win_ptr, new->res_x * 0.96,
		new->res_y * 0.01, 0xff4133, "1 ms");
	mlx_string_put(new->mlx_ptr, new->win_ptr, new->res_x * 0.50,
		new->res_y * 0.01, 0x515c56, "kills:");
	stat = ft_itoa(new->kills);
	mlx_string_put(new->mlx_ptr, new->win_ptr, new->res_x * 0.55,
		new->res_y * 0.01, 0x515c56, stat);
	free(stat);
	mlx_string_put(new->mlx_ptr, new->win_ptr, new->res_x * 0.01,
		new->res_y * 0.01, 250, "x:");
	stat = ft_itoa(new->player_x);
	mlx_string_put(new->mlx_ptr, new->win_ptr, new->res_x * 0.02,
		new->res_y * 0.01, 250, stat);
	free(stat);
	mlx_string_put(new->mlx_ptr, new->win_ptr, new->res_x * 0.04,
		new->res_y * 0.01, 250, "y:");
	stat = ft_itoa(new->player_y);
	mlx_string_put(new->mlx_ptr, new->win_ptr, new->res_x * 0.05,
		new->res_y * 0.01, 250, stat);
	free(stat);
}

void	print_hud(t_pov *new)
{
	int j;

	j = 0;
	ft_sprite(new);
	if (new->reload && new->ammo < 30 && new->index++ > 37)
	{
		new->index = 0;
		new->reload = 0;
		new->ammo = 30;
	}
	texture_hud(new, new->tab[new->index]);
	if (new->shoot && (new->frame % 2 == 0) && new->ammo > 0)
		ft_fire(new);
	ft_weapon(new);
	ft_crosshair(new);
	while (++j <= new->ammo)
		ft_ammo(new, j);
	print_info(new);
}

int		pos_calcultor(void *param)
{
	t_pov	*new;
	int		i;

	new = param;
	i = 0;
	new->frame++;
	read_key(new);
	pos_mouse(new);
	while (i < new->res_x)
	{
		init_calculator(i, new);
		init_calculator2(new);
		detect_wall(new);
		find_start_end(new);
		new->z_buffer[i] = new->perpwalldist;
		draw_vertical_line(i, new);
		i++;
	}
	print_hud(new);
	return (0);
}

int		close_window(t_pov *pov)
{
	mlx_destroy_image(pov->mlx_ptr, pov->img_ptr);
	mlx_destroy_window(pov->mlx_ptr, pov->win_ptr);
	reset_double_ptr(pov->map);
	exit(0);
	return (0);
}

void	reset_mem(t_parse *conf)
{
	free(conf->no);
	free(conf->so);
	free(conf->ea);
	free(conf->we);
	free(conf->s);
}
