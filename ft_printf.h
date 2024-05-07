/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomacias <nomacias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:50:33 by nomacias          #+#    #+#             */
/*   Updated: 2024/04/02 10:33:43 by nomacias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H	
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(long n, int base);
int	ft_puthex(unsigned long long n, const char *basestr);
int	ft_putaddr(unsigned long long p);
int	ft_printf(const char *str, ...);
#endif
