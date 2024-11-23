/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:15:09 by alvapari          #+#    #+#             */
/*   Updated: 2023/10/03 17:46:48 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_intlen(int n)
{
	int	result;

	result = 0;
	if (n < 0)
	{
		n = n * (-1);
		result++;
	}
	if (n == 0)
		result++;
	while (n != 0)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char					*str;
	int						count;
	int						intlen;
	long int				m;

	m = n;
	count = 0;
	intlen = get_intlen(n);
	str = malloc(sizeof(char) * (get_intlen(n)) + 1);
	if (str == NULL)
		return (NULL);
	if (m == 0)
		str[0] = '0';
	if (m < 0)
	{
		m = m * (-1);
		str[0] = '-';
	}
	while (m > 0)
	{
		str[intlen - (count++) - 1] = (m % 10) + '0';
		m = m / 10;
	}
	str[intlen] = '\0';
	return (str);
}
/*
int	main(void)
{
	printf("%d\n", get_intlen(0));
}*/
