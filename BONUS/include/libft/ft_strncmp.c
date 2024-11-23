/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 00:18:24 by alvapari          #+#    #+#             */
/*   Updated: 2023/10/03 17:52:54 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (0);
	while ((unsigned char)s1[count] == (unsigned char)s2[count] && count < n - 1
		&& s1[count] != '\0' && s2[count] != '\0')
	{
		count++;
	}
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}
/*
int	main(void)
{
	printf("%i\n", ft_strncmp("holoo", "holaa", 3));
	printf("%i", strncmp("holoo", "holaa", 3));
	return(0);
}*/