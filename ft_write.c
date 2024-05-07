/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomacias <nomacias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:59:49 by nomacias          #+#    #+#             */
/*   Updated: 2024/04/15 11:40:00 by nomacias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str [i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(long n, int base)
{
	static int	r;
	char		*basestr;

	r = 0;
	basestr = "0123456789abcdef";
	if (n < 0)
	{
		ft_putchar('-');
		return (ft_putnbr(-n, base) + 1);
	}
	else if (n < base)
		r += ft_putchar(basestr[n % base]);
	else
	{
		ft_putnbr(n / base, base);
		r += ft_putchar(basestr[n % base]);
	}
	return (r);
}

int	ft_puthex(unsigned long long n, const char *basestr)
	{
	static int	r;

	r = 0;
	if (n < 16)
		r += ft_putchar(basestr[n % 16]);
	else
	{
		ft_puthex(n / 16, basestr);
		r += ft_putchar(basestr[n % 16]);
	}
	return (r);
}

int	ft_putaddr(unsigned long long p)
{
	write(1, "0x", 2);
	return (ft_puthex(p, "0123456789abcdef") + 2);
}
