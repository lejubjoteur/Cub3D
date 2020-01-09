/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgimenez <qgimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 09:13:57 by qgimenez          #+#    #+#             */
/*   Updated: 2020/01/09 13:51:36 by qgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../mlx/mlx.h"

# define BUFFER_SIZE			100
# define KEYPRESSMASK			1
# define KEYRELEASEMASK			2
# define BUTTONPRESSMASK		4
# define BUTTONRELEASEMASK		8
# define STRUCTURENOTIFYMASK	131072
# define KEYPRESS				2
# define KEYRELEASE				3
# define BUTTONPRESS			4
# define BUTTONRELEASE			5
# define DESTROYNOTIFY			17

typedef struct	s_ctrl
{
	int w;
	int s;
	int a;
	int d;
	int rot_left;
	int rot_right;
}				t_ctrl;

typedef struct	s_sprite
{
	float	x;
	float	y;
	int		txt;
}				t_sprite;

typedef struct	s_txt
{
	float	wall_x;
	int		x;
	int		y;
	int		d;
}				t_txt;

typedef struct	s_rgb
{
	int	red;
	int	green;
	int blue;
}				t_rgb;

typedef struct	s_frame_saver
{
	unsigned char	*buf;
	size_t			index;
	size_t			size;
}				t_frame_saver;

typedef struct	s_parse
{
	int			rendu_x;
	int			rendu_y;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	char		*weapon;
	t_rgb		f;
	t_rgb		c;
	int			pos_x;
	int			pos_y;
	int			dir_x;
	int			dir_y;
	float		plan_x;
	float		plan_y;
	int			nb_sprite;
	int			flag[8];
	char		*line;
	char		**str;
	int			retour;
	int			i;
	int			nbline;
	int			len;
	int			first_len;
	int			bool;
	t_sprite	spr[100];
}				t_parse;

typedef struct	s_img
{
	unsigned char	*data;
	int				bit_per_pixel;
	int				size_line;
	int				endian;
	int				width;
	int				height;
}				t_img;

typedef struct	s_pov
{
	float			player_x;
	float			player_y;
	float			dir_x;
	float			dir_y;
	float			plan_x;
	float			plan_y;
	float			raydir_x;
	float			raydir_y;
	float			camera_x;
	int				map_x;
	int				map_y;
	float			sidedist_x;
	float			sidedist_y;
	float			deltadist_x;
	float			deltadist_y;
	float			perpwalldist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	float			old_dir_x;
	float			old_plan_x;
	int				draw_s;
	int				draw_e;
	int				res_x;
	int				res_y;
	int				line_h;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			**map;
	t_img			img;
	t_rgb			sky;
	t_rgb			floor;
	t_img			txt_n;
	t_img			txt_s;
	t_img			txt_e;
	t_img			txt_w;
	t_img			txt_print;
	float			z_buffer[2560];
	int				nb_sprite;
	int				sprite_order[1000];
	int				sprite_dist[100];
	float			sprite_x;
	float			sprite_y;
	int				sprite_screen_x;
	int				s_drawstart_x;
	int				s_drawstart_y;
	int				s_drawend_x;
	int				s_drawend_y;
	int				sprite_h;
	int				sprite_w;
	int				s_text_x;
	int				s_text_y;
	int				res_x_spr;
	int				res_y_spr;
	t_img			sprite;
	t_sprite		spr[100];
	t_ctrl			ctrl;
	t_img			weapon;
	int				w_drawstart_x;
	int				w_drawstart_y;
	int				w_drawend_x;
	int				w_drawend_y;
	int				weapon_h;
	int				weapon_w;
	int				w_text_x;
	int				w_text_y;
	char			*tab[40];
	int				reload;
	int				index;
	t_img			crosshair;
	int				c_drawstart_x;
	int				c_drawstart_y;
	int				c_drawend_x;
	int				c_drawend_y;
	int				crosshair_h;
	int				crosshair_w;
	int				c_text_x;
	int				c_text_y;
	t_img			fire;
	int				f_drawstart_x;
	int				f_drawstart_y;
	int				f_drawend_x;
	int				f_drawend_y;
	int				fire_h;
	int				fire_w;
	int				f_text_x;
	int				f_text_y;
	t_img			bullet;
	int				a_drawstart_x;
	int				a_drawstart_y;
	int				a_drawend_x;
	int				a_drawend_y;
	int				ammo_h;
	int				ammo_w;
	int				a_text_x;
	int				a_text_y;
	int				shoot;
	int				sneak;
	int				ammo;
	int				kills;
	int				frame;
	int				mouv_x;
	int				focus;
}				t_pov;

int				get_next_line(int fd, char **line);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
size_t			ft_strlen(const char *str);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strchr(const char *s, int c);
int				ft_strncmp(char *s1, const char *s2, size_t n);
char			**ft_split(char const *s, char c);
int				ft_atoi(char *str);
int				parse_r(char **str, t_parse *my_map);
int				parse_no(char **str, t_parse *my_map);
int				parse_so(char **str, t_parse *my_map);
int				parse_we(char **str, t_parse *my_map);
int				parse_ea(char **str, t_parse *my_map);
int				parse_s(char **str, t_parse *my_map);
int				parse_f(char **str, t_parse *my_map);
int				parse_c(char **str, t_parse *my_map);
int				ft_isdigit(int c);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_isalpha(int c);
char			*ft_delspace(char *s);
int				ft_init_window(t_parse *config, char **map, int save);
void			move(float speed, t_pov *new);
void			strafe(float speed, t_pov *new);
void			texture_ciel(int i, int j, t_pov *arg);
void			texture_mur(int i, int j, t_txt *text, t_pov *arg);
void			texture_sol(int i, int j, t_pov *arg);
void			ft_sprite(t_pov *pov);
int				read_key(t_pov *new);
int				key_press(int key, t_pov *pov);
int				key_release(int key, t_pov *pov);
int				texture_hud(t_pov *pov, char *path);
void			ft_weapon(t_pov *pov);
void			init_weapon(t_pov *pov);
void			ft_crosshair(t_pov *pov);
int				texture_crosshair(t_pov *pov);
int				texture_fire(t_pov *pov);
void			ft_fire(t_pov *pov);
void			hit_sprite(t_pov *new);
void			count_sprite(t_pov *pov);
char			*ft_itoa(int n);
void			ft_ammo(t_pov *pov, int nb);
int				texture_ammo(t_pov *pov);
int				pos_mouse(t_pov *pov);
void			mouse_rotation(float rot, t_pov *pov);
void			rotation_pov(float rot, t_pov *pov);
int				mouse_press(int button, int x, int y, t_pov *pov);
int				mouse_release(int button, int x, int y, t_pov *pov);
void			detect_wall(t_pov *new);
void			find_start_end(t_pov *new);
void			init_calculator2(t_pov *new);
void			init_calculator(int i, t_pov *new);
void			draw_vertical_line(int i, t_pov *arg);
void			comb_sort(t_pov *pov);
int				texture_hud(t_pov *pov, char *path);
int				texture_sprite(t_pov *pov, t_parse *config);
int				pos_calcultor(void *param);
int				close_window();
int				only_digit(char *s);
int				ft_error(int code);
int				check_map(t_parse *conf, char *map);
void			p_direction(t_parse *conf, char **map, int i, int j);
void			ft_putstr(char *s);
int				ft_save(t_pov *pov, char *filename);
int				check_format(char *arg);
void			reset_mem(t_parse *config);
void			reset_double_ptr(char **ptr);
char			*ft_strdup(const char *s);
void			ft_duplicatemap(t_pov *pov, char **map);
char			*ft_strjoin_kifree(char *s1, char *s2);

#endif
