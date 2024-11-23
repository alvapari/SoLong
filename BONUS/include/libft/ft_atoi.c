/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:39:28 by alvapari          #+#    #+#             */
/*   Updated: 2023/10/03 17:29:06 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				c;
	unsigned int	result;
	int				sign;

	sign = 1;
	result = 0;
	c = 0;
	while ((str[c] >= '\t' && str[c] <= '\r') || str[c] == 32)
		c++;
	while ((str[c] == '-' || str[c] == '+')
		&& (str[c +1] >= '0' && str[c +1] <= '9'))
	{
		if (str[c] == '-')
			sign = (-1) * sign;
		c++;
	}
	while ((str[c] >= '0' && str[c] <= '9') && str[c] != '\0')
	{
		result = result * 10 + (str[c] - '0');
		c++;
	}
	return ((result) * (sign));
}

/*
int main(void)
{
	const char pr[] = "\b 0484";
	printf("%i\n", ft_atoi(pr));
	printf("%i", atoi(pr));

}*/