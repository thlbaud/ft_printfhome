/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:20:25 by tmouche           #+#    #+#             */
/*   Updated: 2023/11/28 12:13:56 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char			test_c;
	char			*test_str;
	int				test_double;
	int				test_int;
	unsigned int	test_u;
	unsigned int	test_x;
	unsigned int	test_X;
	
	test_c = 'k';
	test_str = "Hello";
	test_double = 3547;
	test_int = 788756;
	test_u = 4575;
	test_x = 4533657;
	test_X = 6659;

	printf("Tester printf ->\n\n");
	if (argv[1][0] == 'c')
	{
		ft_printf("output ft_printf : %c\n", test_c);
		printf("output printf : %c\n", test_c);
		ft_printf("-------------------------------------\n");
	}
	else if (argv[1][0] == 's')
	{
		ft_printf("output ft_printf : %s\n", test_str);
		printf("output printf : %s\n", test_str);
		ft_printf("-------------------------------------\n");
	}
	else if (argv[1][0] == 'd')
	{
		ft_printf("output ft_printf : %d\n", test_double);
		printf("output printf : %d\n", test_double);
		ft_printf("-------------------------------------\n");
	}
	else if (argv[1][0] == 'i')
	{
		ft_printf("output ft_printf : %i\n", test_int);
		printf("output printf : %i\n", test_int);
		ft_printf("-------------------------------------\n");
	}
	else if (argv[1][0] == 'u')
	{
		ft_printf("output ft_printf : %u\n", test_u);
		printf("output printf : %u\n", test_u);
		ft_printf("-------------------------------------\n");
	}	
	else if (argv[1][0] == 'x')
	{
		ft_printf("output ft_printf : %x\n", test_x);
		printf("output printf : %x\n", test_x);
		ft_printf("-------------------------------------\n");
	}
	else if (argv[1][0] == 'X')
	{
		ft_printf("output ft_printf : %X\n", test_X);
		printf("output printf : %X\n", test_X);
		ft_printf("-------------------------------------\n");
	}
	return (0);	
}		