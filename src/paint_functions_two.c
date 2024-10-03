/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_functions_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:23:23 by alvapari          #+#    #+#             */
/*   Updated: 2024/10/03 13:24:58 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

int	ft_next_pos(int32_t height, int32_t width, char key, char **map)
{
	int	control;

	control = 0;
	if (map[height - 1][width] && map[height - 1][width] == '1' && key == 'w')
		control = 1;
	if (map[height][width + 1] && map[height][width + 1] == '1' && key == 'd')
		control = 1;
	if (map[height + 1][width] && map[height + 1][width] == '1' && key == 's')
		control = 1;
	if (map[height][width - 1] && map[height][width - 1] == '1' && key == 'a')
		control = 1;
	return (control);
}

void	ft_add_step(t_data *data, int32_t *position_x, int32_t *position_y, char key)
{
	if (key == 'w')
		*position_y -= 64;
	if (key == 'a')
		*position_x -= 64;
	if (key == 's')
		*position_y += 64;
	if (key == 'd')
		*position_x += 64;
	ft_change_player_position(data, key);
	data->steps++;
	printf("Steps: %i\n", data->steps);
}

void	ft_player_move(mlx_key_data_t keydata, void *data)
{
	t_data	*dataptr;
	int32_t	*position_x;
	int32_t	*position_y;

	dataptr = data;
	/*ft_bye_bye(dataptr);*/
	position_x = &dataptr->images.player_right->instances[0].x;
	position_y = &dataptr->images.player_right->instances[0].y;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_W && ft_next_pos(*position_y / 64,
				*position_x / 64, 'w', dataptr->map.matrix) != 1)
			ft_add_step(dataptr, position_x, position_y, 'w');
		if (keydata.key == MLX_KEY_A && ft_next_pos(*position_y / 64,
				*position_x / 64, 'a', dataptr->map.matrix) != 1)
			ft_add_step(dataptr, position_x, position_y, 'a');
		if (keydata.key == MLX_KEY_S && ft_next_pos(*position_y / 64,
				*position_x / 64, 's', dataptr->map.matrix) != 1)
			ft_add_step(dataptr, position_x, position_y, 's');
		if (keydata.key == MLX_KEY_D && ft_next_pos(*position_y / 64, 
				*position_x / 64, 'd', dataptr->map.matrix) != 1)
			ft_add_step(dataptr, position_x, position_y, 'd');
		if (keydata.key == MLX_KEY_ESCAPE)
			ft_close_window(dataptr);
		ft_open_exit(*dataptr);
	}
}
/*
void	ft_bye_bye(t_data *data)
{
	int32_t	*position_x;
	int32_t	*position_y;
	static int count;
	
	if (count == 0);
	{
		position_x = &data->images.player_right->instances[0].x;
		position_y = &data->images.player_right->instances[0].y;
		data->map.matrix[*position_y / 64][*position_x / 64] = '0';
	}
	count ++;
}*/

void	ft_open_exit(t_data data)
{
	int		count;
	t_data	*ptr;

	count = 0;
	ptr = &data;
	if (data.cnt_colls == data.max_colls)
	{
		data.images.exit->enabled = true;
		if (data.map.matrix[data.images.player_right->instances[0].y
				/ 64][data.images.player_right->instances[0].x / 64] == 'E')
		{
			printf("Congratulations! You won!\n");
			ft_close_window(ptr); 
		}	
	}
}

void	ft_change_player_position(t_data *data, char key)
{
	mlx_texture_t	*texture;
	int32_t			postnx;
	int32_t			postny;
	
	texture = NULL;
	if (key == 'w')
		texture = mlx_load_png("./textures/up.png");
	else if (key == 'a')
		texture = mlx_load_png("./textures/left.png");
	else if (key == 's')
		texture = mlx_load_png("./textures/down.png");
	else if (key == 'd')
		texture = mlx_load_png("./textures/right.png");
	if(!texture)
		exit(1);
	postnx = data->images.player_right->instances[0].x;
	postny = data->images.player_right->instances[0].y;
	data->images.player_right->instances[0].enabled = false;
	data->images.player_right = mlx_texture_to_image(data->mlx, texture);
	mlx_delete_texture(texture);
	mlx_image_to_window(data->mlx, data->images.player_right, postnx, postny);
	data->images.player_right->instances->enabled = true;
}

