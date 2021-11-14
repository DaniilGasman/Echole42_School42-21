/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:22:20 by nfedayki          #+#    #+#             */
/*   Updated: 2021/05/13 06:15:53 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "struct.h"

void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_strlen(char *str);
int				ft_isset(char c, const char *set);
int				ft_strcmp(char *s1, char *s2);

char			*ft_strdup(const char *s1);
int				ft_atoi_base(char *str, char *set);
int				ft_ext_check(char *file_name, char *ext);
int				ft_contains_notset(char *str, char *set);

t_list			*ft_take_last_arg(t_list *alst, int type);
t_list			*ft_lstnew(int type, void *content);
void			ft_add_lst_back(t_list **alst, t_list *new);

void			ft_lst_del_one(t_list **lst, t_list *one);
void			ft_lst_clear_content(t_list *lst);
void			ft_dlist_clear(t_list **lst);

int				my_get_pixel_color(int x, int y, t_data *img);
void			my_mlx_pixel_put(t_data *img, int x, int y, int color);
t_data			my_mlx_new_image(void *mlx, int width, int height);
int				my_mlx_destroy_tx(void *mlx, t_list *elem);
int				my_mlx_tx_from_path(void *mlx, t_list *elem);

t_sprite		*ft_new_sprite_create(int x, int y);
void			ft_put_sprite_front(t_sprite **alst, t_sprite *new);
void			ft_sprite_switch(t_sprite *ptr);
void			ft_clear_list(t_sprite **lst);

char			**ft_split(char const *s, char *set, int i, int k);

char			*ft_strtrim(char const *s1, char const *set);

int				ft_recurcive_gnl(int fd, char **line);

#endif
