/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgimenez <qgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:44:41 by qgimenez          #+#    #+#             */
/*   Updated: 2020/01/08 08:50:59 by qgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	write_int(t_frame_saver *sv, unsigned int val)
{
	sv->buf[sv->index++] = val >> 0;
	sv->buf[sv->index++] = val >> 8;
	sv->buf[sv->index++] = val >> 16;
	sv->buf[sv->index++] = val >> 24;
}

static void	write_file_header(t_frame_saver *sv)
{
	sv->buf[sv->index++] = 'B';
	sv->buf[sv->index++] = 'M';
	write_int(sv, sv->size);
	write_int(sv, 0x00000000);
	sv->buf[sv->index++] = 54;
	sv->buf[sv->index++] = 0;
	sv->buf[sv->index++] = 0;
	sv->buf[sv->index++] = 0;
}

static void	write_file_info(t_pov *pov, t_frame_saver *sv)
{
	int i;

	sv->buf[sv->index++] = 40;
	sv->buf[sv->index++] = 0;
	sv->buf[sv->index++] = 0;
	sv->buf[sv->index++] = 0;
	write_int(sv, pov->res_x);
	write_int(sv, pov->res_y);
	sv->buf[sv->index++] = 1;
	sv->buf[sv->index++] = 0;
	sv->buf[sv->index++] = 24;
	sv->buf[sv->index++] = 0;
	i = 0;
	while (i < 24)
	{
		sv->buf[sv->index++] = 0;
		i++;
	}
}

static void	write_body(t_pov *pov, t_frame_saver *sv)
{
	int x;
	int y;

	y = pov->res_y - 1;
	while (y >= 0)
	{
		x = -1;
		while (++x < pov->res_x)
		{
			sv->buf[sv->index++] = pov->img.data[(x * 4)
			+ (y * pov->img.size_line)];
			sv->buf[sv->index++] = pov->img.data[(x * 4)
			+ (y * pov->img.size_line) + 1];
			sv->buf[sv->index++] = pov->img.data[(x * 4)
			+ (y * pov->img.size_line) + 2];
		}
		x = -1;
		while (++x < (4 - (pov->res_x * 3) % 4) % 4)
			sv->buf[sv->index++] = 0;
		y--;
	}
}

int			ft_save(t_pov *pov, char *filename)
{
	int				fd;
	t_frame_saver	sv;

	sv = (t_frame_saver) { 0 };
	sv.size = 54 + 3 * pov->res_x * pov->res_y +
		((4 - (pov->res_x * 3) % 4) % 4) * pov->res_y;
	sv.buf = malloc(sv.size);
	if (!sv.buf || (fd = open(filename, O_WRONLY | O_CREAT, S_IRUSR)) < 0)
		return (-1);
	write_file_header(&sv);
	write_file_info(pov, &sv);
	write_body(pov, &sv);
	write(fd, sv.buf, sv.size);
	free(sv.buf);
	close(fd);
	return (0);
}
