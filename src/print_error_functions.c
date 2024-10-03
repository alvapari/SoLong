/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 22:07:08 by alvapari          #+#    #+#             */
/*   Updated: 2024/08/29 13:15:57 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	ft_print_map_error(char c)
{
	if (c == 'e')
		printf("Error: the map is empty\n");
	if (c == 'f')
		printf("Error: file should be .ber\n");
	if (c == 'c')
		printf("Error: invalid characters in map\n");
	if (c == 'm')
	{
		printf("Error: there must be collectibles, only one exit");
		printf(" and only one player\n");
	}
	if (c == 's')
	{
		printf("Error: please check map is rectangular and big enough for\n");
		printf(" 1 player, 1 exit and to be surrounded by maps\n");
	}
	if (c == 'r')
		printf("Error: map is not rectangular\n");
	if (c == 'w')
		printf("Error: map must be surrounded by walls\n");    
	if (c == 'W')
		printf("Error: player has not a valid path\n");
    exit(1);
}

