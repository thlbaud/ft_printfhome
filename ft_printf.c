/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:12:08 by tmouche           #+#    #+#             */
/*   Updated: 2023/11/28 12:23:49 by tmouche          ###   ########.fr       */
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
		ft_putstr("-2147483648");
		return (0);
	}
	if (nbr < 0)
	{
		ft_putstr("-");
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		ft_putnbr_base(nbr / base_len, base);
		write(1 , &base[nbr % base_len], 1);
	}
	if (nbr < 10)
		write(1, &base[nbr % base_len], 1);
	return (0);	
}

int	ft_find_conversion(char c, va_list parameters)
{
	int	error_handler;
	
	error_handler = 0;
	if (c == 'c')
		error_handler = ft_putchar(va_arg(parameters, int));
	else if (c == 's')
		error_handler = ft_putstr(va_arg(parameters, char *));
	/*if (c == 'p')*/
	else if (c == 'd')
		error_handler = ft_putnbr_base(va_arg(parameters, int), "0123456789");
	else if (c == 'i')
		error_handler = ft_putnbr_base(va_arg(parameters, int), "0123456789");
	else if (c == 'u')
		error_handler = ft_putnbr_base(va_arg(parameters, unsigned int), "0123456789");
	else if (c == 'x')
		error_handler = ft_putnbr_base(va_arg(parameters, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		error_handler = ft_putnbr_base(va_arg(parameters, unsigned int), "0123456789ABCDEF");
	/*if (c == '%')*/
	return (error_handler);
}

int	ft_printf(const char *prompt, ...)
{
	va_list	parameters;
	size_t	i;
	size_t	count;
	
	i = 0;
	va_start(parameters, prompt);
	while (prompt[i])
	{
		count = 0;
		while (prompt[i] && prompt[i] != '%')
		{
			i++;
			count++;
		}
		if (write(1, &prompt[i - count], count) == -1)
			return (va_end(parameters), -1);
		if (prompt[i] == 0)
			 break;
		if (prompt[i] == '%' && ((prompt[i + 1] >= 'a' && prompt[i + 1] <= 'z') || prompt[i + 1] == 'X' || prompt[i + 1] == '%'))
		{
			if (ft_find_conversion(prompt[i + 1], parameters) == -1)
				return (va_end(parameters), -1);
			i++;
		}
		i++;
	}
	return (va_end(parameters), 0);
}