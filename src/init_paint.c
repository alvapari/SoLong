/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:25:10 by alvapari          #+#    #+#             */
/*   Updated: 2024/10/03 17:20:19 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	ft_init_paint(t_data data)
{
	data.mlx = mlx_init(data.map.width * 64, data.map.height * 64, "so_long",
		false);
	if (!data.mlx)
	{
		printf("%s", mlx_strerror(mlx_errno));
		exit(1);
	}
    data.max_colls = data.cnt_colls;
    ft_create_images(&data);
	ft_create_images_two(&data);
	ft_draw_wall_floor(&data);
	mlx_key_hook(data.mlx, ft_player_move, &data);
	mlx_loop(data.mlx);
	ft_delete_textures_images(&data);
}

void    ft_create_images(t_data *data)
{
	data->images.collectibles = malloc(sizeof(mlx_image_t *) * data->max_colls);
    data->textures.wall = mlx_load_png("./textures/wall.png");
	if (!data->textures.wall)
        exit(1); 
	data->images.wall = mlx_texture_to_image(data->mlx, data->textures.wall);
	if (!data->images.wall)
        exit(1);
 	data->textures.floor = mlx_load_png("./textures/floor.png");
	if (!data->textures.floor)
        exit(1);
	data->images.floor = mlx_texture_to_image(data->mlx, data->textures.floor);
	if (!data->images.floor)
        exit(1);
	ft_collectible_images(data);
}

void    ft_create_images_two(t_data *data)
{
	data->textures.exit = mlx_load_png("./textures/exit.png");
	if (!data->textures.exit)
        exit(1); 
	data->images.exit = mlx_texture_to_image(data->mlx, data->textures.exit);
	if (!data->images.exit)
        exit(1);
	data->textures.player_right = mlx_load_png("./textures/right.png");
	if (!data->textures.player_right)
        exit(1);
	data->images.player_right = mlx_texture_to_image(data->mlx, data->textures.player_right);
	if (!data->images.player_right)
        exit(1);
}

void	ft_collectible_images(t_data *data)
{
	static int		count = 0;
	mlx_texture_t	*texture;

	while (count < data->max_colls)
	{
		texture = mlx_load_png("./textures/col.png");
		if (!texture)
			exit(1); 
		data->images.collectibles[count] = mlx_texture_to_image(data->mlx, texture);
		if (!data->images.collectibles[count])
				exit(1);
		mlx_delete_texture(texture);
		count++;
	}
}

void	ft_close_window(void *data)
{
	t_data	*ptr;
	int	count;

	count = -1;
	ptr = data;
	mlx_close_window(ptr->mlx);
	while(!count == ptr->cnt_colls)
    {
        count++;
        free (ptr->images.collectibles[count]);
    }
	free(ptr->images.collectibles);
	ptr->images.collectibles = NULL;
}


