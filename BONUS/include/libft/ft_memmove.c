/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:10:06 by alvapari          #+#    #+#             */
/*   Updated: 2023/10/03 17:48:55 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t					count;

	count = 0;
	if (dst == NULL && src == NULL)
		return (dst);
	if (dst > src)
	{
		while (len > 0)
		{
			len--;
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		}
	}
	else
	{
		while (count < len)
		{
			((unsigned char *)dst)[count] = ((const unsigned char *)src)[count];
			count++;
		}
	}
	return (dst);
}

/*
int	main(void)
{
	char	src [] = "123456789";
	printf ("%s", memmove(src +1, src, 7));
	printf ("%s\n", ft_memmove(src +1, src, 7));
}*/
