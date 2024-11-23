/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:13:07 by alvapari          #+#    #+#             */
/*   Updated: 2023/10/03 17:48:40 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		c2;
	const unsigned char	*str;
	size_t				count;

	count = 0;
	str = s;
	c2 = c;
	while (count < n && str[count] != c2)
	{
		count++;
	}
	if (count == n)
		return (NULL);
	else
	{
		return ((void *)&str[count]);
	}
}

/*
int main(void)
{
	char ey [] = "holaaaa";
	printf("%s\n", ft_memchr(ey, 'a', 7));
	printf("%s", memchr (ey, 'a', 7));
}*/