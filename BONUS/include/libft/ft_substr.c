/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:43:16 by alvapari          #+#    #+#             */
/*   Updated: 2023/09/21 20:50:38 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sstr;
	size_t	count;

	count = 0;
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len > ft_strlen(&s[start]))
	{
		len = ft_strlen(&s[start]);
	}
	sstr = malloc(len + 1);
	if (sstr == NULL)
		return (NULL);
	while (count < len && s[start] != '\0')
		sstr[count++] = s[start++];
	sstr[count] = '\0';
	return (sstr);
}
/*
int	main(void)
{
	char	*ey;

	printf("\n qué devuelve%s", ft_substr("hola", 34, 5));
}*/