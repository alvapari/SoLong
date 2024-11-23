/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:55:41 by alvapari          #+#    #+#             */
/*   Updated: 2023/10/03 17:30:31 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, unsigned int n)
{
	unsigned int	count;
	int				bz;
	unsigned char	*str;

	str = s;
	count = 0;
	bz = 0;
	while (count < n)
	{
		str[count] = bz;
		count ++;
	}
}

/*
int	main(void)
{
	char holi [] = "eyholfgaasaaaaa";
	printf("%s", holi);
	bzero(holi, 2);
	printf("%s", holi);
}*/
