/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:46:06 by alvapari          #+#    #+#             */
/*   Updated: 2023/10/03 17:57:54 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ptr_dst;
	const unsigned char	*ptr_src;
	size_t				count;
	unsigned char		*ptr;	

	ptr_dst = dst;
	ptr_src = src;
	count = 0;
	if (ptr_dst == NULL && ptr_src == NULL)
		return (0);
	while (count < n)
	{
		ptr = &ptr_dst[count];
		*ptr = ptr_src[count];
		count++;
	}
	return (dst);
}

/*
int	main(void)
{
	char	ey 	 [] = "ABCDEFGHIJKLMN";
	char	eyii [] = "ABCDEFGHIJKLMN";
	memcpy(ey, ey +4, 10);
	printf("%s\n", ey);
	ft_memcpy(eyii, eyii +4, 10);
	printf("%s\n", eyii);
}*/