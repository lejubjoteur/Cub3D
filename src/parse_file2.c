/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgimenez <qgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:30:16 by qgimenez          #+#    #+#             */
/*   Updated: 2020/01/09 09:17:32 by qgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		parse_s(char **str, t_parse *conf)
{
	if ((++conf->flag[5]) != 1)
		return (0);
	if (str[1] && !str[2])
	{
		conf->s = ft_strdup(str[1]);
		return (1);
	}
	return (0);
}

int		parse_f(char **str, t_parse *conf)
{
	char	**color;
	int		i;

	i = 0;
	if ((++conf->flag[6] != 1) || !str[1] || str[2])
		return (0);
	color = ft_split(str[1], ',');
	while (color[i])
		i++;
	if (i != 3)
		return (0);
	if (str[1] && only_digit(color[0]) && only_digit(color[1])
		&& only_digit(color[2]))
	{
		conf->f.red = ft_atoi(color[0]);
		conf->f.green = ft_atoi(color[1]);
		conf->f.blue = ft_atoi(color[2]);
		reset_double_ptr(color);
		if ((conf->f.red < 0 || conf->f.red > 255)
			|| (conf->f.green < 0 || conf->f.green > 255)
			|| (conf->f.blue < 0 || conf->f.blue > 255))
			return (0);
		return (1);
	}
	return (0);
}

int		parse_c(char **str, t_parse *conf)
{
	char	**color;
	int		i;

	i = 0;
	if ((++conf->flag[7] != 1) || !str[1] || str[2])
		return (0);
	color = ft_split(str[1], ',');
	while (color[i])
		i++;
	if (i != 3)
		return (0);
	if (str[1] && only_digit(color[0]) && only_digit(color[1])
		&& only_digit(color[2]))
	{
		conf->c.red = ft_atoi(color[0]);
		conf->c.green = ft_atoi(color[1]);
		conf->c.blue = ft_atoi(color[2]);
		reset_double_ptr(color);
		if ((conf->c.red < 0 || conf->c.red > 255)
			|| (conf->c.green < 0 || conf->c.green > 255)
			|| (conf->c.blue < 0 || conf->c.blue > 255))
			return (0);
		return (1);
	}
	return (0);
}

int		only_digit(char *s)
{
	while (*s)
		if (!ft_isdigit(*s++))
			return (0);
	return (1);
}

int		check_format(char *arg)
{
	while (*arg && *arg != '.')
		arg++;
	if (!ft_strncmp(arg, ".cub", 4) && ft_strlen(arg) == 4)
		return (1);
	return (0);
}
