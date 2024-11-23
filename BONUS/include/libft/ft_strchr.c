/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:25:38 by alvapari          #+#    #+#             */
/*   Updated: 2023/10/03 17:50:12 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	count;

	count = 0;
	while (s[count] != '\0' && s[count] != (char)c)
	{
		count++;
	}
	if (s[count] == (char)c)
	{
		return ((char *) &s[count]);
	}
	return (0);
}
/*
int	main (void)
{
	char hola[] = ".nosé.l.nl.";
	printf("%p", strchr(hola, '\0'));
	printf("\n");
	printf("%p", ft_strchr(hola, '\0'));
}*/
