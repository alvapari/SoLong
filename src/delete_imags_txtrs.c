/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_imags_txtrs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:24:52 by alvapari          #+#    #+#             */
/*   Updated: 2024/09/25 11:35:13 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	ft_delete_textures_images(t_data	*data)
{
    int count;

    count = -1;
	mlx_delete_texture(data->textures.exit);
	mlx_delete_texture(data->textures.floor);
	mlx_delete_texture(data->textures.player_right);
	mlx_delete_texture(data->textures.wall);
    /*while(!count == data->cnt_colls)
    {
        count++;
        mlx_delete_image(data->mlx, data->images.collectibles[count]);
        free (data->images.collectibles[count]);
    }	
    free(data->images.collectibles);*/
    mlx_delete_image(data->mlx, data->images.exit);
	mlx_delete_image(data->mlx, data->images.floor);
	mlx_delete_image(data->mlx, data->images.wall);
	mlx_delete_image(data->mlx, data->images.player_right);
    mlx_terminate(data->mlx);
    write(1, "entras?", 7);
}

/*
void	ft_delete_textures_images(t_data	*data)
{
    int count;

    count = -1;
	mlx_delete_texture(data->textures.exit);
	mlx_delete_texture(data->textures.floor);
	mlx_delete_texture(data->textures.player_right);
	mlx_delete_texture(data->textures.wall);
    while(!count == data->cnt_colls)
    {
        count++;
        mlx_delete_image(data->mlx, data->images.collectibles[count]);
        free (data->images.collectibles[count]);
    }	
    free(data->images.collectibles);
    data->images.collectibles = 0;
    mlx_delete_image(data->mlx, data->images.exit);
	mlx_delete_image(data->mlx, data->images.floor);
	mlx_delete_image(data->mlx, data->images.wall);
	mlx_delete_image(data->mlx, data->images.player_right);
    ft_free_memory(data->map.matrix, data->map.height);
	ft_free_memory(data->map.aux_matrix, data->map.height);
	mlx_close_window(data->mlx);
    mlx_terminate(data->mlx);
}
*/