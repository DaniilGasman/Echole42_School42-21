/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 06:07:02 by nfedayki          #+#    #+#             */
/*   Updated: 2021/05/13 06:19:03 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_UTILS_H
# define CUB_UTILS_H

# include "struct.h"

int				ft_trigger_parse(t_param *prm);

int				ft_parser_line(t_param *prm);

int				ft_id_res_filler(t_param *prm, char **elem);
int				ft_id_path_filler(t_param *prm, char **elem, int id);

int				ft_hcc_filler(t_param *prm, char **elem, int id);

int				ft_parser_map(t_param *prm);

int				ft_map_control(t_param *prm, int x, int y);

int				ft_game_struct_init(t_param *prm, t_render *render,
					t_monitor *screen, int ret);

void			ft_init_ray(int x, t_ray *ray, t_param *prm);
int				ft_ray_cast(t_param *prm);

void			ft_ray_hits_scan(t_ray *ray, t_param *prm);
void			ft_ray_perspective(t_ray *ray, t_param *prm);
void			ft_ray_texture(t_ray *ray, t_param *prm);

void			ft_img_update(t_ray *ray, t_param *prm);
void			ft_fill_buff(t_ray *ray, t_param *prm);
void			ft_fill_line(int x, t_ray *ray, t_param *prm);

void			ft_calc_sprite_draw_val(t_sprite *ptr, t_param *prm);
void			ft_sprite_building(t_ray *ray, t_param *prm);
void			ft_sprite_line_to_buff(t_sprite *ptr, t_ray *ray, t_param *prm);
void			ft_ft_fill_line_sprite(int x, t_ray *ray,
					t_param *prm, t_sprite *ptr);

int				ft_player_init(t_param *prm);

int				ft_pixel_calculate(t_param *prm);

void			ft_pixel_export(t_ray *ray, t_param *prm, t_monitor *screen);

int				ft_key_press(int keycode, t_param *prm);
int				ft_key_release(int keycode, t_param *prm);
int				ft_move(t_param *prm);

void			ft_forward(t_param *prm);
void			ft_backward(t_param *prm);
void			ft_strafe_left(t_param *prm);
void			ft_strafe_right(t_param *prm);

void			ft_rotate_right(t_param *prm);
void			ft_rotate_left(t_param *prm);

int				ft_error(int err_code);

int				ft_render_errors(int err_code);

int				ft_parserr_clean(t_param *prm);
int				ft_clean_render(t_param *prm);
int				ft_exit(int err_code, t_param *prm);
int				ft_x_exit(t_param *prm);

int				foo(t_map *map, int fd, char *buff, int y);
int				foo2(t_map *map, char *tmp, int y);
int				gnl_map_extract(t_map *map, int fd, char *buff, int y);
int				map_check_line(t_map *map, char *tmp);

#endif
