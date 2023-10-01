/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekordi <ekordi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:59:08 by ekordi            #+#    #+#             */
/*   Updated: 2023/04/17 18:25:02 by ekordi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	checker(char s, va_list *args, int *len, int *c)
{
	if (s == 's')
		ft_string(va_arg(*args, char *), len);
	else if (s == 'c')
		ft_putchar(va_arg(*args, int), len);
	else if (s == 'p')
		ft_hexa_address(va_arg(*args, size_t), len);
	else if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(*args, int), len);
	else if (s == '%')
		ft_putchar('%', len);
	else if (s == 'u')
		ft_unsignedint(va_arg(*args, unsigned int), len);
	else if (s == 'x')
		ft_hexa_putnum(va_arg(*args, unsigned int), len, 'x');
	else if (s == 'X')
		ft_hexa_putnum(va_arg(*args, size_t), len, 'X');
	else
	c--;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		c;
	int		len;

	len = 0;
	c = 0;
	va_start(args, format);
	while (format[c] != '\0')
	{
		if (format[c] == '%')
		{
			c++;
			checker(format[c], &args, &len, &c);
			c++;
		}
		else
			ft_putchar(format[c++], &len);
	}
	return (len);
}
