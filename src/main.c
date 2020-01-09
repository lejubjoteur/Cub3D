/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgimenez <qgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 13:36:28 by qgimenez          #+#    #+#             */
/*   Updated: 2020/01/09 14:21:49 by qgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		check_vide(t_parse *conf)
{
	if (!conf->rendu_x)
		return (0);
	if (!conf->rendu_y)
		return (0);
	if (!conf->no)
		return (0);
	if (!conf->so)
		return (0);
	if (!conf->we)
		return (0);
	if (!conf->ea)
		return (0);
	if (!conf->s)
		return (0);
	return (1);
}

int		key_check(char **str, t_parse *conf)
{
	if (!ft_strncmp(str[0], "R", 1) && ft_strlen(str[0]) == 1)
		return (parse_r(str, conf));
	else if (!ft_strncmp(str[0], "NO", 2) && ft_strlen(str[0]) == 2)
		return (parse_no(str, conf));
	else if (!ft_strncmp(str[0], "SO", 2) && ft_strlen(str[0]) == 2)
		return (parse_so(str, conf));
	else if (!ft_strncmp(str[0], "WE", 2) && ft_strlen(str[0]) == 2)
		return (parse_we(str, conf));
	else if (!ft_strncmp(str[0], "EA", 2) && ft_strlen(str[0]) == 2)
		return (parse_ea(str, conf));
	else if (!ft_strncmp(str[0], "S", 1) && ft_strlen(str[0]) == 1)
		return (parse_s(str, conf));
	else if (!ft_strncmp(str[0], "F", 1) && ft_strlen(str[0]) == 1)
		return (parse_f(str, conf));
	else if (!ft_strncmp(str[0], "C", 1) && ft_strlen(str[0]) == 1)
		return (parse_c(str, conf));
	return (0);
}

int		ft_parse(int fd, t_parse *conf, char **map)
{
	while ((conf->retour = get_next_line(fd, &conf->line)) > 0)
	{
		conf->str = ft_split(conf->line, ' ');
		if (conf->str[0] && !ft_isdigit(*conf->str[0]))
		{
			if (!key_check(conf->str, conf))
				return (ft_error(6));
		}
		else if (conf->str[0] && ft_isdigit(*conf->str[0]) && !check_vide(conf))
			return (ft_error(7));
		else if (conf->str[0] && ft_isdigit(*conf->str[0]))
		{
			*map = ft_strjoin_kifree(*map, conf->line);
			*map = ft_strjoin_kifree(*map, "\n");
		}
		free(conf->line);
		reset_double_ptr(conf->str);
	}
	*map = ft_strjoin_kifree(*map, conf->line);
	*map = ft_strjoin_kifree(*map, "\n");
	*map = ft_delspace(*map);
	if (!check_map(conf, *map))
		return (0);
	close(fd);
	return (1);
}

void	config_pos(t_parse *conf, char **map)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (!ft_isalpha(map[i][j]))
	{
		if (j == (int)ft_strlen(*map) - 1 && map[i + 1])
		{
			j = 0;
			i++;
		}
		else
			j++;
	}
	p_direction(conf, map, i, j);
}

int		main(int argc, char **argv)
{
	int			fd;
	t_parse		conf;
	char		*map;
	char		**map_conv;
	int			save;

	conf = (t_parse){ 0 };
	save = 0;
	if (argc < 2 || argc > 3)
		return (ft_error(1));
	if (argv[2] && !ft_strncmp(argv[2], "--save", 6) && ft_strlen(argv[2]) == 6)
		save = 1;
	else if (argv[2])
		return (ft_error(1));
	if (!check_format(argv[1]) || (fd = open(argv[1], O_RDONLY)) < 0)
		return (ft_error(8));
	if (!(map = ft_calloc(1, 1)) || !ft_parse(fd, &conf, &map))
		return (0);
	map_conv = ft_split(map, '\n');
	config_pos(&conf, map_conv);
	return (ft_init_window(&conf, map_conv, save));
}
