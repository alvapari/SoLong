/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:29:59 by alvapari          #+#    #+#             */
/*   Updated: 2024/09/23 12:41:38 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

t_data	ft_init_data(t_data data)
{
	data.images.player_right = 0;
	data.images.floor = 0;
	data.images.wall = 0;
	data.images.collectibles = 0;
	data.images.exit = 0;
	data.textures.exit = 0;
	data.textures.floor = 0;
	data.textures.player_right = 0;
	data.textures.wall = 0;
	data.map.matrix = 0;
	data.map.aux_matrix = 0;
	data.map.width = 0;
	data.map.height = 0;
	data.cnt_colls = 0;
	data.max_colls = 0;
	data.steps = 0;
	data.player_position_x = 0;
	data.player_position_y = 0;
	return (data);
}
