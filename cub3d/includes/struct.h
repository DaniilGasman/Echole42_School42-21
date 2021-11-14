/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:21:08 by nfedayki          #+#    #+#             */
/*   Updated: 2021/05/16 18:44:22 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_parser
{
	int				fd;
	char			*buff;
	char			**id_strings;
}				t_parser;

typedef struct s_monitor
{
	int				width;
	int				height;
}				t_monitor;

typedef struct s_hcc
{
	unsigned int	hcc;
}				t_hcc;

typedef struct s_int_coord
{
	int				x;
	int				y;
}				t_int_coord;

typedef struct s_coord
{
	double			x;
	double			y;
}				t_coord;

typedef struct s_map
{
	char			**grid;
	int				size_x;
	int				size_y;
	int				my;
}				t_map;

typedef struct s_player
{
	t_coord			pos;
	t_coord			dir;
	t_coord			plane;
	double			view_angle;
}				t_player;

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}				t_data;

typedef struct s_texture
{
	t_data			data;
	int				width;
	int				height;
}				t_texture;

typedef struct s_sprite
{
	t_coord			pos;
	t_coord			sprite;
	t_coord			transform;
	t_int_coord		draw_start;
	t_int_coord		draw_end;
	t_int_coord		tex;
	int				sprite_screen_x;
	int				sprite_width;
	int				sprite_height;
	double			dist;
	double			inv_det;
	struct s_sprite	*next;
	struct s_sprite	*prev;
}				t_sprite;

typedef struct s_list
{
	int				type;
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_render
{
	void			*mlx;
	void			*win;
	t_data			current;
}				t_render;

typedef struct s_config
{
	double			front_speed;
	double			back_speed;
	double			strafe_speed;
	double			rot_speed;
}				t_config;

typedef struct s_ray
{
	t_data		img;
	t_coord		dir;
	t_coord		side_dist;
	t_coord		delta_dist;
	t_int_coord	map;
	t_int_coord	pos;
	t_int_coord	tex;
	t_int_coord	step;
	t_int_coord	side;
	t_sprite	*sprites;
	t_texture	*tx_ptr;
	double		camera_x;
	double		perp_wall_dist;
	double		dist;
	double		wall_x;
	double		tex_step;
	double		tex_pos;
	int			*line_buff;
	int			hit;
	int			color;
	int			id_side;
	int			line_height;
	int			draw_start;
	int			draw_end;
}				t_ray;

typedef struct s_param
{
	unsigned int	booleans;
	void			*ptr;
	t_list			*dlist;
}				t_param;

#endif
