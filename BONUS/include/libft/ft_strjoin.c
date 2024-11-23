/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:40:41 by alvapari          #+#    #+#             */
/*   Updated: 2024/05/05 18:31:16 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	size_t	count;
	size_t	count2;

	count = 0;
	count2 = 0;
	nstr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (nstr == NULL)
		return (NULL);
	while (s1[count])
		nstr[count2++] = s1[count++];
	count = 0;
	while (s2[count] != '\0')
		nstr[count2++] = s2[count++];
	nstr[count2++] = '\0';
	return (nstr);
}

/*
int	main(void)
{
	char	*st1 = "hola";
	char	*st2 = " tio";
	char	*st3 = ft_strjoin(st1, st2);
	printf("%s\n", st3);
	free(st3);
}*/