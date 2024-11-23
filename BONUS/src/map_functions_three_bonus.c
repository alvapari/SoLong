/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions_three.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:06:49 by alvapari          #+#    #+#             */
/*   Updated: 2024/10/06 20:38:36 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

char	**ft_get_mtrx(char *map_file, int width, int height)
{
	char	**mtrx;

	mtrx = malloc(sizeof(char *) * (height + 1));
	if (!mtrx)
		return (NULL);
	mtrx = ft_row_by_row(mtrx, map_file, width, height);
	return (mtrx);
}

char	**ft_row_by_row(char **mtrx, char *map_file, int width, int height)
{
	int		cnt;
	int		cnt_2;
	int		cnt_3;

	cnt = 0;
	cnt_2 = 0;
	cnt_3 = 0;
	while (cnt < height && map_file[cnt_2])
	{
		mtrx[cnt] = malloc(sizeof(char) * width + 1);
		if (!mtrx[cnt])
			return (NULL);
		while (map_file[cnt_2] != '\0' && map_file[cnt_2] != '\n')
		{
			mtrx[cnt][cnt_3] = map_file[cnt_2];
			cnt_2++;
			cnt_3++;
		}
		mtrx[cnt][cnt_3] = '\0';
		cnt_3 = 0;
		cnt_2++;
		cnt++;
	}
	mtrx[height] = 0;
	return (mtrx);
}

void	ft_free_memory(char **mtrx, int height)
{
	int	count;

	count = 0;
	while (count < height)
	{
		free(mtrx[count]);
		count++;
	}
	free(mtrx);
}

void	ft_flood_fill(char	**mtrx, int cur_x, int cur_y, t_data *data)
{
	if (cur_x < 0 || cur_y < 0 || cur_x >= data->map.width
		|| cur_y >= data->map.height || mtrx[cur_y][cur_x] == '1'
		|| mtrx[cur_y][cur_x] == 'F' || mtrx[cur_y][cur_x] == 'N')
		return ;
	mtrx[cur_y][cur_x] = 'F';
	ft_flood_fill(mtrx, cur_x + 1, cur_y, data);
	ft_flood_fill(mtrx, cur_x - 1, cur_y, data);
	ft_flood_fill(mtrx, cur_x, cur_y + 1, data);
	ft_flood_fill(mtrx, cur_x, cur_y - 1, data);
}

void	ft_check_way(char	**mtrx, t_data *data)
{
	int	cnt;
	int	cnt_2;

	cnt = 0;
	while (mtrx[cnt])
	{
		cnt_2 = 0;
		while (mtrx[cnt][cnt_2])
		{
			if (mtrx[cnt][cnt_2] == 'E' || mtrx[cnt][cnt_2] == 'C')
			{
				ft_free_memory(mtrx, data->map.height);
				ft_free_memory(data->map.mtrx, data->map.height);
				ft_print_way_error('W');
			}
			cnt_2++;
		}
		cnt++;
	}
}
