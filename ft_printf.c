/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:12:08 by tmouche           #+#    #+#             */
/*   Updated: 2023/11/28 18:40:08 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	ft_putnbr_base(ssize_t nbr, char *base, size_t *len)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (*len == -1)
		return ;
	if (nbr < 0)
	{
		ft_counter(len, write(1, "-", 1));
		nbr *= -1;
	}
	if (nbr >= base_len)
	{
		ft_putnbr_base(nbr / base_len, base, len);
		ft_counter(len, write(1, &base[nbr % base_len], 1));
		if (*len == -1)
			return ;
	}
	if (nbr < base_len)
		ft_counter(len, write(1, &base[nbr % base_len], 1));
	return ;
}

void	ft_putnbr_bu(size_t nbr, char *base, size_t *len)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (*len == -1)
		return ;
	if (nbr >= base_len)
	{
		ft_putnbr_bu(nbr / base_len, base, len);
		ft_counter(len, write(1, &base[nbr % base_len], 1));
		if (*len == -1)
			return ;
	}
	if (nbr < base_len)
		ft_counter(len, write(1, &base[nbr % base_len], 1));
	return ;
}

void	ft_print_memory(size_t nbr, size_t *len)
{
	if ((char *)nbr == NULL)
	{
		*len = ft_putstr("(nil)", 0);
		if (*len == -1)
			return ;
	}
	*len = ft_putstr("0x" ,0);
	if (*len == -1)
		return ;
	ft_putnbr_bu(nbr, "0123456789abcdef", len);
	if (*len == -1)
		return ;
	*len += 2;
}

size_t	ft_find_conversion(char c, va_list para)
{
	size_t	*len;
	
	*len = 0;
	if (c == 'c')
		ft_putchar(va_arg(para, int));
	else if (c == 's')
		ft_putstr(va_arg(para, char *), 0);
	else if (c == 'p')
		ft_print_memory(va_arg(para, size_t), len);
	else if (c == 'd' || c == 'i')
		ft_putnbr_base(va_arg(para, int), "0123456789", len);
	else if (c == 'u')
		ft_putnbr_bu(va_arg(para, unsigned int), "0123456789", len);
	else if (c == 'x')
		ft_putnbr_bu(va_arg(para, unsigned int), "0123456789abcdef", len);
	else if (c == 'X')
		ft_putnbr_bu(va_arg(para, unsigned int), "0123456789ABCDEF", len);
	else if (c == '%')
		ft_counter(len ,write(1, "%", 1));
	return (*len);
}

int	ft_printf(const char *prompt, ...)
{
	va_list	para;
	size_t	i;
	size_t	total[1];
	size_t	check;

	i = -1;
	*total = 0;
	va_start(para, prompt);
	if (!prompt)
		return (-1);
	while (prompt[++i])
	{
	 	ft_counter(total, ft_putstr((char *)prompt, i));
		if (*total == -1)
			return (va_end(para), -1);
		if (prompt[i] == 0)
			break ;
		if (prompt[i] == '%' && prompt[i + 1])
		{
			ft_counter(total, ft_find_conversion(prompt[++i], para));
			if (*total == -1)
				return (va_end(para), -1);
		}
	}
	return (va_end(para), (int)*total);
}
