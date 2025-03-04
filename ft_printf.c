/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarouj <mgarouj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:20:24 by mgarouj           #+#    #+#             */
/*   Updated: 2024/12/24 00:26:31 by mgarouj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_frmt(va_list args, char frmt)
{
	if (frmt == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (frmt == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (frmt == 'p')
		return (ft_put_pointer(va_arg(args, void *)));
	else if (frmt == 'i' || frmt == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (frmt == 'u')
		return (ft_put_unsigned(va_arg(args, unsigned int)));
	else if (frmt == 'x')
		return (ft_put_hex(va_arg(args, unsigned int), 0));
	else if (frmt == 'X')
		return (ft_put_hex(va_arg(args, unsigned int), 1));
	else if (frmt == '%')
		return (ft_putchar('%'));
	else
		return (ft_putchar(frmt));
	return (0);
}

int	ft_printf(const char *frmt, ...)
{
	va_list	p;
	size_t	i;
	int		lenght;

	lenght = 0;
	i = 0;
	va_start(p, frmt);
	while (frmt[i])
	{
		if (frmt[i] == '%' && !frmt[i + 1])
			break ;
		if (frmt[i] == '%' && frmt[i + 1])
		{
			lenght += ft_frmt(p, frmt[i + 1]);
			i++;
		}
		else
			lenght += ft_putchar(frmt[i]);
		i++;
	}
	va_end(p);
	if (lenght < 0)
		return (lenght * -1);
	return (lenght);
}
