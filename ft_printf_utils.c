/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:11:39 by tmouche           #+#    #+#             */
/*   Updated: 2023/11/28 14:41:56 by tmouche          ###   ########.fr       */
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
	return (0);
}

int	ft_putstr(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (write(1, &str[0], len) == -1)
		return (-1);
	return (0);
}
