/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarouj <mgarouj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:03:53 by mgarouj           #+#    #+#             */
/*   Updated: 2024/12/09 20:38:19 by mgarouj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_put_pointer(void *p)
{
	unsigned long	add;
	int				len;

	if (!p)
		return (write(1, "0x0", 3));
	len = 0;
	add = (unsigned long)p;
	len += ft_putstr("0x");
	len += ft_put_hex(add, 0);
	return (len);
}
