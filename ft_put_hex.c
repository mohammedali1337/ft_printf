/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarouj <mgarouj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:28:05 by mgarouj           #+#    #+#             */
/*   Updated: 2024/12/03 14:50:01 by mgarouj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_set_hex(unsigned long n, int upper)
{
	int		len;
	char	*base;

	len = 0;
	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n > 15)
		len += ft_set_hex(n / 16, upper);
	len += ft_putchar(base[n % 16]);
	return (len);
}

int	ft_put_hex(unsigned long n, int upper)
{
	return (ft_set_hex(n, upper));
}
