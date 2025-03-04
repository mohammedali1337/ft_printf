/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarouj <mgarouj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:52:06 by mgarouj           #+#    #+#             */
/*   Updated: 2024/12/15 20:40:16 by mgarouj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *frmt, ...);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_put_hex(unsigned long n, int upper);
int	ft_putnbr(int n);
int	ft_put_pointer(void *p);
int	ft_put_unsigned(unsigned int num);

#endif