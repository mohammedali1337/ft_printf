/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarouj <mgarouj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:40:27 by mgarouj           #+#    #+#             */
/*   Updated: 2024/12/09 20:38:29 by mgarouj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putnbr(int n)
{
	long	nb;
	int		len;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb = -nb;
	}
	if (nb <= 9)
		len += ft_putchar(nb + '0');
	else
	{
		len += ft_putnbr(nb / 10);
		len += ft_putnbr(nb % 10);
	}
	return (len);
}
