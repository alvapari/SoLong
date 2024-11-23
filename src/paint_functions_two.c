/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_functions_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:23:23 by alvapari          #+#    #+#             */
/*   Updated: 2024/10/06 19:05:29 by alvapari         ###   ########.fr       */
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

void	ft_add_step(t_data *data, int old_plx_pos, int old_ply_pos, char key)
{
	int	new_x;
	int	new_y;

	new_x = old_plx_pos;
	new_y = old_ply_pos;
	if (key == 'w')
		new_y -= 1;
	else if (key == 'a')
		new_x -= 1;
	else if (key == 's')
		new_y += 1;
	else if (key == 'd')
		new_x += 1;
	if (data->map.mtrx[new_y][new_x] == 'C')
		ft_collectibles_management(data, new_x, new_y);
	data->player_position_x = new_x;
	data->player_position_y = new_y;
	data->images.player->instances[0].x = new_x * 64;
	data->images.player->instances[0].y = new_y * 64;
	data->steps++;
	ft_change_player_position(data, key);
	ft_printf("Steps: %i\n", data->steps);
	if (data->map.mtrx[new_y][new_x] == 'E'
		&& data->cnt_colls == (data->max_colls * 2))
		ft_win_management(data);
}

void	ft_win_management(t_data *data)
{
	write(1, "Congratulations! You won!\n", 26);
	ft_close_window(data);
}

void	ft_collectibles_management(t_data *data, int new_x, int new_y)
{
	int	count;
	int	pixel_x;
	int	pixel_y;

	count = 0;
	pixel_x = new_x * 64;
	pixel_y = new_y * 64;
	data->cnt_colls++;
	data->map.mtrx[new_y][new_x] = '0';
	while (count < data->max_colls)
	{
		if (data->images.collectibles[count]->instances[0].x == pixel_x
			&& data->images.collectibles[count]->instances[0].y == pixel_y)
		{
			data->images.collectibles[count]->instances[0].enabled = false;
		}
		count++;
	}
}

void	ft_change_player_position(t_data *data, char key)
{
	mlx_texture_t	*texture;

	texture = NULL;
	if (key == 'w')
		texture = data->textures.player_up;
	else if (key == 'a')
		texture = data->textures.player_left;
	else if (key == 's')
		texture = data->textures.player_down;
	else if (key == 'd')
		texture = data->textures.player_right;
	if (!texture)
		exit(1);
	if (data->images.player)
		mlx_delete_image(data->mlx, data->images.player);
	data->images.player = mlx_texture_to_image(data->mlx, texture);
	if (!data->images.player)
		exit(1);
	mlx_image_to_window(data->mlx, data->images.player, data->player_position_x
		* 64, data->player_position_y * 64);
}
