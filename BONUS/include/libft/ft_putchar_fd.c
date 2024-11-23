/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:02:47 by alvapari          #+#    #+#             */
/*   Updated: 2023/10/03 17:49:03 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
int	main(void)
{
	int fd = open("newfile.txt", O_RDWR | O_CREAT | O_TRUNC);
	if (fd < 0)
	{
		return (1);
	}
	ft_putchar_fd('H', fd);
	ft_putchar_fd('e', fd);
	ft_putchar_fd('y', fd);
	ft_putchar_fd('\n', fd);
	close(fd);
	return (0);
}*/