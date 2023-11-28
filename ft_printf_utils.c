/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:11:39 by tmouche           #+#    #+#             */
/*   Updated: 2023/11/28 22:17:18 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '%')
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

ssize_t	ft_putstr(char *str, size_t i)
{
	size_t	len;

	len = ft_strlen(str);
	if (write(1, &str[i], len) == -1)
		return (-1);
	return (len);
}

size_t	ft_counter(int *total, int len)
{
	if (len == -1)
		*total = -1;
	else
		*total += len;
	return (*total);
}
