/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarouj <mgarouj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:20:24 by mgarouj           #+#    #+#             */
/*   Updated: 2024/12/24 00:25:57 by mgarouj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	skip_repeated_flags(char *str, char c, int *i)
{
	while (str[*i] == c)
		(*i)++;
	return (str[*i]);
}

static int	handle_flags(char *s, int *i, va_list args)
{
	unsigned int	num2;
	int				len;
	int				num;
	char			flag;
	char			next;

	len = 0;
	flag = s[*i];
	next = skip_repeated_flags(s, flag, i);
	if ((flag == '+' || flag == ' ') && (next == 'd' || next == 'i'))
	{
		num = va_arg(args, int);
		if (num >= 0)
			len += write(1, &flag, 1);
	}
	if (flag == '#' && (next == 'x' || next == 'X'))
	{
		num2 = va_arg(args, unsigned int);
		if (num2)
		{
			len += ft_putchar('0');
			len += write(1, &next, 1);
		}
	}
	return (len);
}

static int	print_variable(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_put_pointer(va_arg(args, void *)));
	else if (format == 'i' || format == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_put_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_put_hex(va_arg(args, unsigned int), 0));
	else if (format == 'X')
		return (ft_put_hex(va_arg(args, unsigned int), 1));
	else if (format == '%')
		return (ft_putchar('%'));
	else
		return (ft_putchar(format));
	return (0);
}

static int	process_string(const char *s, va_list args, va_list c)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && !s[i + 1])
			break ;
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			if (s[i] == '#' || s[i] == '+' || s[i] == ' ')
				len += handle_flags((char *)s, &i, c);
			if (s[i])
				len += print_variable(s[i], args);
		}
		else
			len += write(1, &s[i], 1);
		i++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;
	va_list	c;

	va_start(args, str);
	va_copy(c, args);
	len = process_string(str, args, c);
	va_end(args);
	if (len < 0)
		return (len * -1);
	return (len);
}
