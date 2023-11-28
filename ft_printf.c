/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:12:08 by tmouche           #+#    #+#             */
/*   Updated: 2023/11/28 15:11:20 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_putnbr_base(ssize_t nbr, char *base)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		ft_putstr("-");
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		ft_putnbr_base(nbr / base_len, base);
		write(1, &base[nbr % base_len], 1);
	}
	if (nbr < 10)
		write(1, &base[nbr % base_len], 1);
	return (0);
}

int	ft_putnbr_base_ul(size_t nbr, char *base)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (nbr >= 10)
	{
		ft_putnbr_base(nbr / base_len, base);
		write(1, &base[nbr % base_len], 1);
	}
	if (nbr < 10)
		write(1, &base[nbr % base_len], 1);
	return (0);
}

int	ft_print_memory(size_t nbr)
{
	if ((char *)nbr == NULL)
	{
		ft_putstr("(nil)");
		return (0);
	}
	if (ft_putstr("0x") == -1)
		return (-1);
	if (ft_putnbr_base_ul(nbr, "0123456789abcdef"))
		return (-1);
	return (0);
}

int	ft_find_conversion(char c, va_list para)
{
	int	err;

	err = 0;
	if (c == 'c')
		err = ft_putchar(va_arg(para, int));
	else if (c == 's')
		err = ft_putstr(va_arg(para, char *));
	else if (c == 'p')
		err = ft_print_memory(va_arg(para, size_t));
	else if (c == 'd' || c == 'i')
		err = ft_putnbr_base(va_arg(para, int), "0123456789");
	else if (c == 'u')
		err = ft_putnbr_base(va_arg(para, unsigned int), "0123456789");
	else if (c == 'x')
		err = ft_putnbr_base(va_arg(para, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		err = ft_putnbr_base(va_arg(para, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		err = write(1, "%", 1);
	return (err);
}

int	ft_printf(const char *prompt, ...)
{
	va_list	para;
	size_t	i;
	size_t	count;

	i = -1;
	va_start(para, prompt);
	if (!prompt)
		return (-1);
	while (prompt[++i])
	{
		count = 0;
		while (prompt[i] && prompt[i] != '%')
		{
			i++;
			count++;
		}
		if (write(1, &prompt[i - count], count) == -1)
			return (va_end(para), -1);
		if (prompt[i] == 0)
			break ;
		if (prompt[i] == '%' && ((prompt[i + 1] >= 'a' && prompt[i + 1] <= 'z')
				|| prompt[i + 1] == 'X' || prompt[i + 1] == '%'))
			if (ft_find_conversion(prompt[++i], para) == -1)
				return (va_end(para), -1);
	}
	return (va_end(para), 0);
}
