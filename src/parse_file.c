/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgimenez <qgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:28:43 by qgimenez          #+#    #+#             */
/*   Updated: 2020/01/09 09:17:34 by qgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		parse_r(char **str, t_parse *conf)
{
	if (str[1] && str[2] && !str[3] && only_digit(str[1]) && only_digit(str[2]))
	{
		if ((++conf->flag[0]) != 1)
			return (0);
		if ((conf->rendu_x = ft_atoi(str[1])) < 100)
			conf->rendu_x = 100;
		else if ((conf->rendu_x = ft_atoi(str[1])) > 2560)
			conf->rendu_x = 2560;
		if ((conf->rendu_y = ft_atoi(str[2])) < 100)
			conf->rendu_y = 100;
		else if ((conf->rendu_y = ft_atoi(str[2])) > 1440)
			conf->rendu_y = 1440;
		return (1);
	}
	return (0);
}

int		parse_no(char **str, t_parse *conf)
{
	if ((++conf->flag[1]) != 1)
		return (0);
	if (str[1] && !str[2])
	{
		conf->no = ft_strdup(str[1]);
		return (1);
	}
	return (0);
}

int		parse_so(char **str, t_parse *conf)
{
	if ((++conf->flag[2]) != 1)
		return (0);
	if (str[1] && !str[2])
	{
		conf->so = ft_strdup(str[1]);
		return (1);
	}
	return (0);
}

int		parse_we(char **str, t_parse *conf)
{
	if ((++conf->flag[3]) != 1)
		return (0);
	if (str[1] && !str[2])
	{
		conf->we = ft_strdup(str[1]);
		return (1);
	}
	return (0);
}

int		parse_ea(char **str, t_parse *conf)
{
	if ((++conf->flag[4]) != 1)
		return (0);
	if (str[1] && !str[2])
	{
		conf->ea = ft_strdup(str[1]);
		return (1);
	}
	return (0);
}
