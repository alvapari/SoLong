/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:42:40 by alvapari          #+#    #+#             */
/*   Updated: 2024/10/06 18:21:41 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	ft_draw_function(t_data *data, int count, int count2)
{
	if (data->map.mtrx[count][count2] == '1')
		mlx_image_to_window(data->mlx, data->images.wall, count2 * 64,
			count * 64);
	if (data->map.mtrx[count][count2] == '0')
		mlx_image_to_window(data->mlx, data->images.floor, count2 * 64,
			count * 64);
	if (data->map.mtrx[count][count2] == 'C')
		ft_draw_col(count, count2, data);
	if (data->map.mtrx[count][count2] == 'E')
	{
		mlx_image_to_window(data->mlx, data->images.floor, count2 * 64,
			count * 64);
		mlx_image_to_window(data->mlx, data->images.exit, count2 * 64,
			count * 64);
	}
}

void	ft_draw_col(int count, int count2, t_data	*data)
{
	static int	count3 = 0;

	mlx_image_to_window(data->mlx, data->images.floor, count2 * 64, count * 64);
	if (count3 < data->max_colls)
	{
		mlx_image_to_window(data->mlx, data->images.collectibles[count3],
			count2 * 64, count * 64);
		count3++;
	}
}

void	ft_draw_player(t_data *data)
{
	int	count;
	int	count2;

	count = 0;
	while (data->map.mtrx[count])
	{
		count2 = 0;
		while (data->map.mtrx[count][count2])
		{
			if (data->map.mtrx[count][count2] == 'P')
			{
				ft_player(count, count2, data);
				data->player_position_x = count2;
				data->player_position_y = count;
			}
			count2++;
		}
		count++;
	}
}

void	ft_player(int height, int width, t_data *data)
{
	mlx_image_to_window(data->mlx, data->images.floor, width * 64, height * 64);
	mlx_image_to_window(data->mlx, data->images.player, width * 64,
		height * 64);
}

void	ft_player_move(mlx_key_data_t keydata, void *data)
{
	t_data	*dataptr;
	int32_t	*position_x;
	int32_t	*position_y;

	dataptr = data;
	position_x = &dataptr->player_position_x;
	position_y = &dataptr->player_position_y;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_W && ft_next_pos(*position_y, *position_x,
				'w', dataptr->map.mtrx) != 1)
			ft_add_step(dataptr, *position_x, *position_y, 'w');
		if (keydata.key == MLX_KEY_A && ft_next_pos(*position_y, *position_x,
				'a', dataptr->map.mtrx) != 1)
			ft_add_step(dataptr, *position_x, *position_y, 'a');
		if (keydata.key == MLX_KEY_S && ft_next_pos(*position_y, *position_x,
				's', dataptr->map.mtrx) != 1)
			ft_add_step(dataptr, *position_x, *position_y, 's');
		if (keydata.key == MLX_KEY_D && ft_next_pos(*position_y, *position_x,
				'd', dataptr->map.mtrx) != 1)
			ft_add_step(dataptr, *position_x, *position_y, 'd');
		if (keydata.key == MLX_KEY_ESCAPE)
			ft_close_window(dataptr);
	}
}
