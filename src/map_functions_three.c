/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions_three.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:06:49 by alvapari          #+#    #+#             */
/*   Updated: 2024/10/05 13:39:02 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

char	**ft_create_matrix(char *map_file, int width, int height)
{
	char	**matrix;

	matrix = malloc(sizeof(char *) * (height + 1));
	if (!matrix)
		return (NULL);
	matrix = ft_row_by_row(matrix, map_file, width, height);
	return (matrix);
}

char	**ft_row_by_row(char **matrix, char *map_file, int width, int height)
{
	int		cnt;
	int		cnt_2;
	int		cnt_3;

	cnt = 0;
	cnt_2 = 0;
	cnt_3 = 0;
	while (cnt < height && map_file[cnt_2])
	{
		matrix[cnt] = malloc(sizeof(char) * width + 1);
		if (!matrix[cnt])
			return (NULL);
		while (map_file[cnt_2] != '\0' && map_file[cnt_2] != '\n')
		{
			matrix[cnt][cnt_3] = map_file[cnt_2];
			cnt_2++;
			cnt_3++;
		}
		matrix[cnt][cnt_3] = '\0';
		cnt_3 = 0;
		cnt_2++;
		cnt++;
	}
	matrix[height] = 0;
	return (matrix);
}

void	ft_free_memory(char **matrix, int height)
{
	int	count;

	count = 0;
	while (count < height)
	{
		free(matrix[count]);
		count++;
	}
	free(matrix);
}

void	ft_flood_fill(char	**matrix, int cur_x, int cur_y, t_data *data)
{
	if(cur_x < 0 || cur_y < 0 || cur_x >= data->map.width || cur_y >= data->map.height || matrix[cur_y][cur_x] == '1' || matrix[cur_y][cur_x] == 'F')
		return ;
	matrix[cur_y][cur_x] = 'F';
	ft_flood_fill(matrix, cur_x + 1, cur_y, data);
	ft_flood_fill(matrix, cur_x - 1, cur_y, data);
	ft_flood_fill(matrix, cur_x, cur_y + 1, data);
	ft_flood_fill(matrix, cur_x, cur_y - 1, data);
}

void	ft_check_way(char	**matrix, t_data *data)
{
	int cnt;
	int	cnt_2;
	
	cnt = 0;
	while (matrix[cnt])
	{
		cnt_2 = 0;
		while(matrix[cnt][cnt_2])
		{
			if(matrix[cnt][cnt_2] == 'E' || matrix[cnt][cnt_2] == 'C')
			{
				ft_free_memory(matrix, data->map.height);
				ft_free_memory(data->map.matrix, data->map.height);
				ft_print_way_error('W');
			}	
			cnt_2++;
		}
		cnt++;
	}
}