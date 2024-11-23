/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:11:55 by alvapari          #+#    #+#             */
/*   Updated: 2024/05/10 23:10:23 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cntwords(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static void	ft_free(char **str)
{
	char	**ptr;

	if (!str)
		return ;
	ptr = str;
	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(str);
}

static int	ft_wordlen(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		str_ind;

	str_ind = -1;
	i = 0;
	str = malloc(sizeof(char *) * (ft_cntwords(s, c) + 1));
	if (!str)
		return (NULL);
	while (++str_ind < ft_cntwords(s, c))
	{
		while (s[i] == c)
			i++;
		str[str_ind] = ft_substr(s, i, ft_wordlen(s, c, i));
		if (!(str[str_ind]))
		{
			ft_free(str);
			return (NULL);
		}
		i += ft_wordlen(s, c, i);
	}
	str[str_ind] = NULL;
	return (str);
}
/*
int	main(void)
{
	char	*s;
	char	**splitted;
	int		i;

	s = "                  olol";
	splitted = ft_split(s, ' ');
	i = 0;
	while (splitted[i])
	{
		printf("%s\n", splitted[i]);
		i++;
	}
	free(splitted);
	return (0);
}*/
