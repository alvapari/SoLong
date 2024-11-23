/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 22:07:08 by alvapari          #+#    #+#             */
/*   Updated: 2024/10/06 17:16:29 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	ft_free_map(char *map)
{
	free(map);
	map = NULL;
	exit(1);
}

void	ft_print_map_error_two(char c)
{
	if (c == 'f')
		ft_printf("Error: file should be .ber\n");
	if (c == 'e')
		ft_printf("Error: the map is empty\n");
	exit(1);
}

void	ft_print_map_error(char c, char	*map)
{
	if (c == 'c')
		ft_printf("Error: invalid characters in map\n");
	if (c == 'm')
	{
		ft_printf("Error: there must be collectibles, only one exit");
		ft_printf(" and only one player\n");
	}
	if (c == 's')
	{
		ft_printf("Error: please check map is rectangular and big enough");
		ft_printf(" for 1 player, 1 exit and to be surrounded by maps\n");
	}
	if (c == 'r')
		ft_printf("Error: map is not rectangular\n");
	if (c == 'w')
		ft_printf("Error: map must be surrounded by walls\n");
	ft_free_map(map);
}

void	ft_print_way_error(char c)
{
	if (c == 'W')
	{
		ft_printf("Error: player has not a valid path\n");
		exit(1);
	}
}
