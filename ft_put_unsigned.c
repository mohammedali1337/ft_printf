/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarouj <mgarouj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:27:52 by mgarouj           #+#    #+#             */
/*   Updated: 2024/12/03 14:53:02 by mgarouj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned(unsigned int num)
{
	if (num >= 10)
		return (ft_put_unsigned(num / 10) + ft_putchar((num % 10) + 48));
	return (ft_putchar(num + 48));
}
