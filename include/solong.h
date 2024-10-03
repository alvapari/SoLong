/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:16:33 by alvapari          #+#    #+#             */
/*   Updated: 2024/10/03 17:20:15 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../MLX42-master/include/MLX42/MLX42.h"
# include "libft.h"

typedef struct  s_map
{
    char    **matrix;
    char    **aux_matrix;
    int width;
    int height;
}   t_map;

typedef struct s_images
{
    mlx_image_t	*player_right; 
	mlx_image_t	*floor; 
	mlx_image_t	*wall; 
	mlx_image_t	**collectibles;
	mlx_image_t	*exit; 
} t_images;

typedef struct s_textures
{
    mlx_texture_t	*player_right; 
	mlx_texture_t	*floor; 
	mlx_texture_t	*wall; 
	mlx_texture_t	*exit; 
} t_textures;

typedef struct s_data
{
    mlx_t		*mlx;
    t_map       map;
    t_images    images;
    t_textures  textures;
    int			player_position_x;
	int			player_position_y;
	int			cnt_colls;
	int			max_colls;
	int			steps;
} t_data;

t_data  ft_init_data(t_data data);
char    *ft_read_berfile(char *argv);
void    ft_print_map_error(char   c);
void    ft_check_format(char    *argv);
void	ft_check_map(char *map, t_data *data);
void    ft_check_characters(char *map, t_data *data, int count);
void    ft_check_minimum_size(char *map);
void    ft_check_rectangular(char *map);
t_data  ft_get_hw(char  *map_file, t_data data);
t_data  ft_create_window(t_data data, char *map_file);
void    ft_check_walls(char *map, int width, int height);
void    ft_check_downright(char *map, int width, int height, int count);
void    ft_check_topleft(char *map, int width, int height);
char	**ft_create_matrix(char *map_file, int width, int height);
char	**ft_row_by_row(char **matrix, char *map_file, int width, int height);
void	ft_flood_fill(char	**matrix, int current_x, int current_y, t_data *data);
void	ft_free_memory(char	**matrix, int height);
void	ft_check_way(char	**matrix, t_data *data);
void    ft_init_paint(t_data data);
void    ft_create_images(t_data *data);
void    ft_create_images_two(t_data *data);
void    ft_draw_wall_floor(t_data *data);
void	ft_draw_col(int count, int count2, t_data	*data);
void    ft_exit_img(t_data  *data);
void	ft_delete_textures_images(t_data	*data);
void	ft_collectible_images(t_data *data);
void	ft_player(int height, int width, t_data *data);
void	ft_draw_player(t_data *data);
void	ft_close_window(void *data);
void	ft_player_move(mlx_key_data_t keydata, void *data);
void	ft_add_step(t_data *data, int32_t *position_x, int32_t *position_y, char key);
int	    ft_next_pos(int32_t height, int32_t width, char key, char **map);
void	ft_change_player_position(t_data *data, char key);
void	ft_open_exit(t_data data);

#endif