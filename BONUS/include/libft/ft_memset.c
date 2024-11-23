/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:23:48 by alvapari          #+#    #+#             */
/*   Updated: 2023/10/03 18:08:43 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			count;
	unsigned char	*ptr;
	unsigned char	uc;

	ptr = b;
	uc = c;
	count = 0;
	while (count < len)
	{
		ptr[count] = uc;
		count++;
	}
	return (ptr);
}

/*
int	main(void)
{
	char hola [] = "Holayadios";
	printf("%s\n", ft_memset(hola, 65, 40));
	printf("%s", memset(hola, 65, 40));
}*/
