/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarouj <mgarouj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:27:52 by mgarouj           #+#    #+#             */
/*   Updated: 2024/12/09 20:38:23 by mgarouj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_put_unsigned(unsigned int num)
{
	if (num >= 10)
		return (ft_put_unsigned(num / 10) + ft_putchar((num % 10) + 48));
	return (ft_putchar(num + 48));
}
