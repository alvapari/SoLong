/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:16:33 by alvapari          #+#    #+#             */
/*   Updated: 2024/10/06 23:11:51 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include "MLX42.h"
# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char			**mtrx;
	char			**aux_mtrx;
	int				width;
	int				height;
}					t_map;

typedef struct s_images
{
	mlx_image_t		*player;
	mlx_image_t		*floor;
	mlx_image_t		*wall;
	mlx_image_t		**collectibles;
	mlx_image_t		*exit;
	mlx_image_t		*enemie;
	mlx_image_t		*steps_on_screen;
}					t_images;

typedef struct s_textures
{
	mlx_texture_t	*player_down;
	mlx_texture_t	*enemie;
	mlx_texture_t	*player_right;
	mlx_texture_t	*player_left;
	mlx_texture_t	*player_up;
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*exit;
}					t_textures;

typedef struct s_data
{
	mlx_t			*mlx;
	t_map			map;
	t_images		images;
	t_textures		textures;
	int				player_position_x;
	int				player_position_y;
	int				cnt_colls;
	int				max_colls;
	int				steps;
}					t_data;

int					ft_next_pos(int32_t height, int32_t width, char key,
						char **map);
t_data				ft_init_data(t_data data);
char				*ft_read_berfile(char *argv);
void				ft_print_map_error(char c, char *map);
void				ft_print_map_error_two(char c);
void				ft_print_way_error(char c);
void				ft_check_format(char *argv);
void				ft_check_map(char *map, t_data *data);
void				ft_check_characters(char *map, t_data *data, int count);
void				ft_check_minimum_size(char *map);
void				ft_check_rectangular(char *map);
t_data				ft_get_hw(char *map_file, t_data data);
t_data				ft_create_window(t_data data, char *map_file);
void				ft_check_walls(char *map, int width, int height);
void				ft_check_downright(char *map, int width, int height,
						int count);
void				ft_check_topleft(char *map, int width, int height);
char				**ft_get_mtrx(char *map_file, int width, int height);
void				ft_get_position(int count, t_data *data);
char				**ft_row_by_row(char **mtrx, char *map_file, int width,
						int height);
void				ft_flood_fill(char **mtrx, int current_x, int current_y,
						t_data *data);
void				ft_free_memory(char **mtrx, int height);
void				ft_check_way(char **mtrx, t_data *data);
void				ft_init_paint(t_data data);
void				ft_create_images(t_data *data);
void				ft_create_images_two(t_data *data);
void				ft_draw_wall_floor(t_data *data);
void				ft_draw_col(int count, int count2, t_data *data);
void				ft_exit_img(t_data *data);
void				ft_delete_textures_images(t_data *data);
void				ft_collectible_images(t_data *data);
void				ft_player(int height, int width, t_data *data);
void				ft_draw_player(t_data *data);
void				ft_close_window(void *data);
void				ft_player_move(mlx_key_data_t keydata, void *data);
void				ft_add_step(t_data *data, int old_plx_pos, int old_ply_pos,
						char key);
void				ft_change_player_position(t_data *data, char key);
void				ft_redraw_cell(t_data *data, int x, int y);
void				ft_remove_exit_image(t_data *data);
void				ft_free_map(char *map);
void				ft_collectibles_management(t_data *data, int new_x,
						int new_y);
void				ft_draw_function(t_data *data, int count, int count2);
void				ft_print_steps(t_data *data);
void				ft_win_and_lose_management(t_data *data, int new_y,
						int new_x);

#endif