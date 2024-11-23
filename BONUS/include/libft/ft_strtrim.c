/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:13:52 by alvapari          #+#    #+#             */
/*   Updated: 2023/09/21 19:31:23 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_startposition(char const *s1, char const *set)
{
	size_t	startcount;
	size_t	count;
	char	endwhile;

	endwhile = '0';
	startcount = 0;
	while (s1[startcount] != '\0' && endwhile != 'c')
	{
		count = 0;
		while (s1[startcount] != set[count] && set[count] != '\0')
			count++;
		if (s1[startcount] == set[count])
			startcount++;
		else
			endwhile = 'c';
	}
	return (startcount);
}

size_t	ft_endposition(char const *s1, char const *set)
{
	size_t	endcount;
	size_t	count;
	char	endwhile;

	endwhile = '0';
	endcount = (ft_strlen(s1) - 1);
	while (s1[endcount] != '\0' && endwhile != 'c')
	{
		count = 0;
		while (s1[endcount] != set[count] && set[count] != '\0')
			count++;
		if (s1[endcount] == set[count])
			endcount--;
		else
		{
			endwhile = 'c';
			endcount++;
		}
	}
	return (endcount);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	startposition;
	size_t	endposition;

	if (s1[0] == '\0' || (s1[0] == '\0' && set[0] == '\0'))
		endposition = 0;
	else
		endposition = (ft_endposition(s1, set));
	startposition = ft_startposition(s1, set);
	trimmed = ft_substr(s1, startposition, (endposition - startposition));
	return (trimmed);
}
/*
int	main(void)
{
	char	*s1;
	char	*set;

	s1 = ",,,hola,,,,,";
	set = ",";
	printf("%s", ft_strtrim(s1, set));
}*/
