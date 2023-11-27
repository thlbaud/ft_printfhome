/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:12:08 by tmouche           #+#    #+#             */
/*   Updated: 2023/11/27 15:12:42 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

int	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (nbr == -2147483648)
	{
		ft_putstr("-2147483648", 11);
		return (0);
	}
	if (nbr < 0)
	{
		ft_putstr("-", 1);
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		ft_putnbr_base(nbr / base_len, base);
		write(1 , &base[nbr % base_len], 1);
	}
	write(1, &base[nbr % base_len], 1);
	return (0);	
}

int	ft_find_conversion(char c, va_list parameters)
{
	int	error_handler;
	
	error_handler = 0;
	if (c == 'c')
		error_handler = ft_putstr(va_arg(parameters, char *), 1);
	if (c == 's')
		error_handler = ft_putstr(va_arg(parameters, char *), 5);
	/*if (c == 'p')*/
	if (c == 'd')
		error_handler = ft_putnbr_base(va_arg(parameters, double), "0123456789");
	/*if (c == 'i')
		error_handler = ft_putnbr_base(va_args(parameters, int), "0123456789");
	if (c == 'u')
		error_handler = ft_putnbr_base(va_args(parameters, unsigned double), "0123456789");
	if (c == 'x')
		error_handler = ft_putnbr_base(va_args(parameters, int), "0123456789abcdef");
	if (c == 'X')
		error_handler = ft_putnbr_base(va_args(parameters, int), "0123456789ABCDEF");
	if (c == '%')*/
}

int	ft_printf(const char *, ...)
{
	va_list(parameters);
	char	*format;
	size_t	i;
	
	i = 0;
	va_start(parameters, format);
	format = va_arg(parameters, char *);
	while (format[i])
	{
		while (format[i] && format[i] != '%')
			i++;
		if (ft_putstr(format, i) == -1)
			return (-1);
		if (format[i] == '%')
			i++;
		if ((format[i] >= 'a' && format[i] <= 'z') || format[i] == 'X' 
				|| format[i] == '%')
			if (ft_find_conversion(format[i], parameters) == -1)
				return (-1);
		i++;
	}
	va_end(parameters);
	return (0);
}