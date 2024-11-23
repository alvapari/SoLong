/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:24:52 by alvapari          #+#    #+#             */
/*   Updated: 2024/05/10 23:01:33 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strleng(char *str)
{
	int	cnt;

	cnt = 0;
	if (!str)
		return (0);
	while (str[cnt] != '\0')
		cnt++;
	return (cnt);
}

char	*ft_strchr_gnl(char *str, char c)
{
	int	cnt;

	cnt = 0;
	if (!str)
		return (0);
	while (str[cnt] != '\0')
	{
		if (str[cnt] == c)
			return (&str[cnt]);
		cnt++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *buffer, char *buffer_aux)
{
	char	*res;
	int		cnt;
	int		cnt2;

	if (!buffer_aux)
	{
		buffer_aux = malloc(1);
		buffer_aux[0] = '\0';
	}
	if (!buffer_aux || !buffer)
		return (0);
	res = malloc(sizeof(char) * (ft_strleng(buffer) + ft_strleng(buffer_aux))
			+ 1);
	if (!res)
		return (0);
	cnt = -1;
	cnt2 = 0;
	if (buffer_aux)
		while (buffer_aux[++cnt] != '\0')
			res[cnt] = buffer_aux[cnt];
	while (buffer[cnt2] != '\0')
		res[cnt++] = buffer[cnt2++];
	res[cnt] = '\0';
	free(buffer_aux);
	return (res);
}
