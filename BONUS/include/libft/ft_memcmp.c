/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:41:14 by alvapari          #+#    #+#             */
/*   Updated: 2024/02/07 18:27:12 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;
	size_t				count;

	count = 0;
	ptr1 = s1;
	ptr2 = s2;
	while ((count < n) && (ptr1[count] == ptr2[count]))
	{
		count ++;
	}
	if (count == n)
		return (0);
	else
		return (ptr1[count] - ptr2[count]);
}

/*
int	main(void)
{
	char hola [] = "HolY, Maricarmen";
	char hola2 [] = "Hola, Maricarmen";
	printf("%i\n", ft_memcmp(hola, hola2, -1));
	printf("%i", memcmp(hola, hola2, -1));
}*/