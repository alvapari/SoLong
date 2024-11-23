/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:55:05 by alvapari          #+#    #+#             */
/*   Updated: 2023/09/08 13:55:28 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstr;
	unsigned int	count;

	count = 0;
	newstr = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (newstr == NULL)
		return (NULL);
	while (count < ft_strlen(s))
	{
		newstr[count] = f(count, s[count]);
		count++;
	}
	newstr[count] = s[count];
	return (newstr);
}
/*
char	f(unsigned int i, char c)
{
	i = 32;
	return (c - i);
}

int	main(void)
{
	printf("%s", ft_strmapi("holae", &f));
}
*/