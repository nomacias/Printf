/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomacias <nomacias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:50:33 by nomacias          #+#    #+#             */
/*   Updated: 2024/04/15 11:44:22 by nomacias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_char(va_list *ap, char c)
{
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	if (c == 'd')
		return (ft_putnbr(va_arg(*ap, int), 10));
	if (c == 'i')
		return (ft_putnbr(va_arg(*ap, int), 10));
	if (c == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	if (c == 'p')
		return (ft_putaddr(va_arg(*ap, unsigned long long)));
	if (c == 'u')
		return (ft_putnbr(va_arg(*ap, unsigned int), 10));
	if (c == 'x')
		return (ft_puthex(va_arg(*ap, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_puthex(va_arg(*ap, unsigned int), "0123456789ABCDEF"));
	return (0);
}

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	int		rt;
	int		i;

	if (write(1, "", 0) < 0)
		return (-1);
	va_start(ap, str);
	i = 0;
	rt = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			rt += parse_char(&ap, str[i + 1]);
			i++;
		}
		else
			rt += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (rt);
}
