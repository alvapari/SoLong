/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_functions_three.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:04:02 by alvapari          #+#    #+#             */
/*   Updated: 2024/10/06 21:03:26 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	ft_print_steps(t_data *data)
{
	char	*steps;
	char	*shown;

	steps = ft_itoa(data->steps);
	shown = ft_strjoin("Steps: ", steps);
	data->images.steps_on_screen = mlx_put_string(data->mlx, shown, 1, 1);
	ft_printf("Steps: %i\n", data->steps);
	free(steps);
	free(shown);
	mlx_image_to_window(data->mlx, data->images.steps_on_screen, 1, 1);
}
