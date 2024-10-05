/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:16:28 by alvapari          #+#    #+#             */
/*   Updated: 2024/10/05 13:50:17 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	char	*map_file;

	map_file = 0;
	if (argc != 2)
		printf("Usage: <./so_long> <map.ber>\n");
	else
	{
		data.mlx = 0;
		data = ft_init_data(data);
		map_file = ft_read_berfile(argv[1]);
		data = ft_get_hw(map_file, data);
		ft_check_map(map_file, &data);
		ft_check_walls(map_file, data.map.width, data.map.height);
		data.map.matrix = ft_create_matrix(map_file, data.map.width, 
				data.map.height); 
		data.map.aux_matrix = ft_create_matrix(map_file, data.map.width, 
				data.map.height);
		free(map_file);
		ft_flood_fill(data.map.aux_matrix, data.player_position_x, data.player_position_y, &data);
		ft_check_way(data.map.aux_matrix, &data);
		ft_init_paint(data);
		ft_free_memory(data.map.matrix, data.map.height);
		ft_free_memory(data.map.aux_matrix, data.map.height);
	}
}