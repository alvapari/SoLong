/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:42:40 by alvapari          #+#    #+#             */
/*   Updated: 2024/10/03 14:32:58 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	ft_draw_wall_floor(t_data *data)
{
	int	count;
	int	count2;

	count = 0;
	while (data->map.matrix[count])
	{
		count2 = 0;
		while (data->map.matrix[count][count2])
		{
			if (data->map.matrix[count][count2] == '1')
				mlx_image_to_window(data->mlx, data->images.wall, count2 * 64, count * 64);
			if (data->map.matrix[count][count2] == '0')
				mlx_image_to_window(data->mlx, data->images.floor, count2 * 64, count * 64);
			if (data->map.matrix[count][count2] == 'C')
				ft_draw_col(count, count2, data);
			if (data->map.matrix[count][count2] == 'E')
			{
				mlx_image_to_window(data->mlx, data->images.floor, count2 * 64, count * 64);
				mlx_image_to_window(data->mlx, data->images.exit, count2 * 64, count * 64);
			}
				count2++;
		}
		count++;
	}
}

void	ft_draw_col(int count, int count2, t_data	*data)
{
	static int	count3 = 0;

	mlx_image_to_window(data->mlx, data->images.floor, count2 * 64, count * 64);
	if (count3 < data->max_colls)
	{
		mlx_image_to_window(data->mlx, data->images.collectibles[count3], count2 * 64, count * 64);
		count3++;
	}
	ft_draw_player(data);
}

void	ft_draw_player(t_data *data)
{
	int	count;
	int	count2;

	count = 0;
	while (data->map.matrix[count])
	{
		count2 = 0;
		while (data->map.matrix[count][count2])
		{
			if (data->map.matrix[count][count2] == 'P')
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
	mlx_image_to_window(data->mlx, data->images.player_right, width * 64, height * 64);
}
