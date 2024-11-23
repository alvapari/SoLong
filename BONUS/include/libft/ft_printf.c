/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:28:11 by alvapari          #+#    #+#             */
/*   Updated: 2024/05/10 23:02:37 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(char const *str, ...)
{
	int		cnt;
	int		total;
	va_list	lst;

	va_start(lst, str);
	cnt = 0;
	total = 0;
	while (str[cnt] != '\0')
	{
		if (str[cnt] != '%')
			total = total + ft_putchar(str[cnt]);
		else
		{
			cnt++;
			total = total + get_specifiers(lst, str[cnt]);
		}
		cnt++;
	}
	va_end(lst);
	return (total);
}

int	get_specifiers(va_list lst, char c)
{
	if (c == 's')
		return (ft_putstr(va_arg(lst, char *)));
	if (c == 'c')
		return (ft_putchar(va_arg(lst, int)));
	if (c == 'd')
		return (ft_putint(va_arg(lst, int)));
	if (c == 'i')
		return (ft_putint(va_arg(lst, int)));
	if (c == 'u')
		return (ft_putui(va_arg(lst, unsigned int)));
	if (c == 'p')
		return (ft_putpntr(va_arg(lst, unsigned long int)));
	if (c == 'X')
		return (ft_puthexu(va_arg(lst, unsigned int)));
	if (c == 'x')
		return (ft_puthexl(va_arg(lst, unsigned int)));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}
