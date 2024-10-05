/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:26:57 by alvapari          #+#    #+#             */
/*   Updated: 2024/10/05 14:05:39 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	ft_check_format(char *argv)
{
	int	cnt;

	cnt = 0;
	while (argv[cnt] != '\0')
		cnt++;
	if (argv[cnt - 1] != 'r' || argv[cnt - 2] != 'e' || argv[cnt - 3] != 'b'
		|| argv[cnt - 4] != '.')
	{
		ft_print_map_error_two('f');
	}
}

char	*ft_read_berfile(char *argv)
{
	char	*read_file;
	char	buff;
	int		cnt;
	int		fd;

	cnt = 0;
	ft_check_format(argv);
	fd = open(argv, O_RDONLY);
	while (read(fd, &buff, 1) == 1)
		cnt++;
	if (cnt == 0)
		ft_print_map_error_two('e');
	read_file = malloc(sizeof(char) * cnt + 1);
	if (!read_file)
		return (NULL);
	cnt = 0;
	fd = open(argv, O_RDONLY);
	while (read(fd, &buff, 1) == 1)
	{
		read_file[cnt] = buff;
		cnt++;
	}
	read_file[cnt] = '\0';
	close(fd);
	return (read_file);
}

void	ft_check_map(char *map, t_data *data)
{
	int	count;
	
	count = 0;
	ft_check_characters(map, data, count);
	ft_check_minimum_size(map);
}

void	ft_check_characters(char *map, t_data *data, int count)
{
	int	cnt_exit;
	int	cnt_player;

	cnt_exit = 0;
	cnt_player = 0;
	count = 0;
	while (map[count])
	{
		if (map[count] != '1' && map[count] != '0' && map[count] != 'E'
			&& map[count] != 'C' && map[count] != 'P' && map[count] != '\n')
			ft_print_map_error('c', map);
		if (map[count] == 'E')
			cnt_exit++;
		if (map[count] == 'P')
		{
			cnt_player++;
			data->player_position_x = (count - (count / (data->map.width + 1))) % data->map.width;
			data->player_position_y = (count - (count / (data->map.width + 1))) / data->map.width;
		}
		if (map[count] == 'C')
			data->cnt_colls++;
		count++;
	}
	if (cnt_exit != 1 || cnt_player != 1 || data->cnt_colls == 0)
		ft_print_map_error('m', map);
}