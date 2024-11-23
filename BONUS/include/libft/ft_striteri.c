/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:01:29 by alvapari          #+#    #+#             */
/*   Updated: 2023/09/11 12:25:16 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	count;
	unsigned int	slen;

	slen = 0;
	count = 0;
	while (s[slen] != '\0')
	{
		slen++;
	}
	while (count < slen)
	{
		f(count, &s[count]);
		count++;
	}
}
/*
void f(unsigned int i, char *c)
{
	if (i < 10)
		*c = ft_toupper(&c);
}

int	main(void)
{
	char	c[] = "holaaaaaaa";
	ft_striteri(c, &f);
	printf("%s", c);
	return (0);
}*/
