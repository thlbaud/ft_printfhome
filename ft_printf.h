/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:13:41 by tmouche           #+#    #+#             */
/*   Updated: 2023/11/29 11:51:13 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>

int		ft_putchar(char c);
ssize_t	ft_putstr(char *str);
int		ft_printf(const char *prompt, ...);
size_t	ft_strlen(const char *s);
ssize_t	ft_putstr_stoped(char *str);
size_t	ft_counter(int *total, int len);

#endif