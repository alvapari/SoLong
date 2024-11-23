/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:40:21 by alvapari          #+#    #+#             */
/*   Updated: 2023/10/03 18:54:38 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*sdup;
	int		size;

	size = 1 + (ft_strlen(s));
	sdup = malloc(sizeof(char) * size);
	if (s == NULL || sdup == NULL)
		return (NULL);
	ft_strlcpy(sdup, s, size);
	return (sdup);
}
/*
int main ()
{
	char *p = "hola123456789";
	char *pp = "hola123456789";
	printf("%s\n", ft_strdup (p));
	printf("%s", strdup(pp));
}*/
