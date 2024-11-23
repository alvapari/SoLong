/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:44:59 by alvapari          #+#    #+#             */
/*   Updated: 2024/05/10 23:03:28 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_ulent(unsigned int num)
{
	int	cnt;

	cnt = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num = num / 10;
		cnt++;
	}
	return (cnt);
}

int	ft_putui(unsigned int i)
{
	int	cnt_chr;

	cnt_chr = get_ulent(i);
	if (i >= 10)
	{
		ft_putui (i / 10);
		ft_putui (i % 10);
	}
	else
	{
		i = i + '0';
		write (1, &i, 1);
	}
	return (cnt_chr);
}
