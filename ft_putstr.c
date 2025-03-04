/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarouj <mgarouj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:44:43 by mgarouj           #+#    #+#             */
/*   Updated: 2024/12/03 14:53:36 by mgarouj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	lenght;
	int	i;

	i = 0;
	lenght = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
	{
		lenght += write(1, &s[i], 1);
		i++;
	}
	return (lenght);
}
