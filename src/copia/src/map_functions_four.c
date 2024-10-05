/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions_four.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:32:45 by alvapari          #+#    #+#             */
/*   Updated: 2024/10/05 13:33:17 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void 	ft_check_walls(char *map, int width, int height)
{
	int	count;

	count = 0;
    ft_check_topleft(map, width, height);
    ft_check_downright(map, width, height, count);
}

void	ft_check_topleft(char *map, int width, int height)
{
	int	count;
	int	count2;

	count2 = 0;
	count = 0;
	while (map[count] != '\n')
	{
		if (map[count] != '1')
			ft_print_map_error('w', map);
		count++;
	}
	count = 0;
	while (count < height)
	{
		if (map[count2] != '1')
			ft_print_map_error('w', map);
		count2 = count2 + width + 1;
		count++;
	}
}

void	ft_check_downright(char *map, int width, int height, int count)
{
	int	count2;

	count2 = 1;
	while (map[count] && count2 < height)
	{
		if (map[count] == '\n')
			count2++;
		count++;
	}
	while (map[count] && map[count] != '\n')
	{
		if (map[count] != '1')
			ft_print_map_error('w', map);
		count++;
	}
	count2 = width - 1;
	count = 0;
	while (count < height)
	{
		if (map[count2] != '1')
			ft_print_map_error('w', map);
		count2 = count2 + width + 1;
		count++;
	}
}