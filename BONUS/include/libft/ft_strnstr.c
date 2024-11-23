/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:11:32 by alvapari          #+#    #+#             */
/*   Updated: 2023/06/25 13:16:12 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hs_count;
	size_t	nd_size;

	nd_size = 0;
	hs_count = 0;
	if (needle[hs_count] == 0)
		return ((char *)haystack);
	if (haystack[hs_count] == 0)
		return (NULL);
	while (needle[nd_size] != '\0')
		nd_size++;
	if (len < nd_size)
		return (0);
	while (haystack[hs_count] && hs_count + nd_size <= len)
	{
		if (ft_strncmp(haystack + hs_count, needle, nd_size) == 0)
			return ((char *)(&haystack[hs_count]));
		hs_count++;
	}
	return (NULL);
}
