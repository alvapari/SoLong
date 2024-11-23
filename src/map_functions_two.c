/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:57:22 by alvapari          #+#    #+#             */
/*   Updated: 2024/10/06 17:24:32 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	ft_check_minimum_size(char *map)
{
	int	count;
	int	width;
	int	height;

	count = 0;
	width = 0;
	height = 0;
	while (map[width] && map[width] != '\n')
		width++;
	while (map[count])
	{
		if (map[count] == '\n')
			height++;
		count++;
	}
	if (height * width < 15)
		ft_print_map_error('s', map);
	if (map[(height * width) + height - 2] == '\0')
		ft_print_map_error('r', map);
	ft_check_rectangular(map);
}

void	ft_check_rectangular(char *map)
{
	int	count;
	int	width;
	int	count_control;

	width = 0;
	count_control = 0;
	count = 0;
	while (map[width] && map[width] != '\n')
		width++;
	while (map[count] != '\0')
	{
		if (map[count + 1] == '\0' && width - count_control != 1
			&& map[count] != '\n')
			ft_print_map_error('r', map);
		if (map[count] == '\n')
		{
			if (count_control != width)
				ft_print_map_error('r', map);
			count_control = -1;
		}
		count++;
		count_control++;
	}
}

t_data	ft_get_hw(char *map_file, t_data data)
{
	int	count;
	int	width;
	int	height;

	count = 0;
	width = 0;
	height = 0;
	while (map_file[width] && map_file[width] != '\n')
		width++;
	data.map.width = width;
	while (map_file[count])
	{
		if (map_file[count] == '\n')
			height++;
		count++;
	}
	data.map.height = height;
	return (data);
}
