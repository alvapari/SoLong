/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:44:02 by alvapari          #+#    #+#             */
/*   Updated: 2023/10/03 19:02:40 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*aux;

	aux = malloc(nmemb * size);
	if (aux == NULL)
		return (NULL);
	ft_bzero(aux, nmemb * size);
	return (aux);
}

/*
int	main(void)
{
	char      *prb;
	char     *jeje;

	prb = malloc(sizeof(char) * 42);
	jeje = "1, 2, 98, 99, 100, 355";
	printf("%d\n", prb[32]);
	prb = jeje;
	printf("%d\n", prb[32]);
}*/