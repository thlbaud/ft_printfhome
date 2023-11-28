/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:20:25 by tmouche           #+#    #+#             */
/*   Updated: 2023/11/28 15:34:35 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	main(int argc, char **argv)
{
	int				i;
	int				test_d;
	unsigned int	test_u;
	unsigned int	test_x;
	unsigned int	test_X;
	char			test_pc;
	void			*test_p;

	test_u = 4575;
	test_x = 4533657;
	test_X = 6659;
	test_pc = '%';
	test_p = "ehuhew";

	printf("Tester printf ->\n\n");
	if (argv[1][0] == 'c')
	{
		for (i = 0; i <= 127; i++)
		{
			ft_printf("output ft_printf : %c\n", (char)i);
			printf("output printf : %c\n", (char)i);
			ft_printf("-------------------------------------\n");
		}
	}
	else if (argv[1][0] == 's')
	{
		ft_printf("output ft_printf : %s\n", argv[2]);
		printf("output printf : %s\n", argv[2]);
		ft_printf("-------------------------------------\n");
		ft_printf("output ft_printf NULL : %s\n", "\0");
		printf("output printf NULL : %s\n", "\0");
		ft_printf("-------------------------------------\n");
	}
	else if (argv[1][0] == 'd')
	{
		srand(time(NULL));
		test_d = rand() % 10;
		printf("input : %i\n", test_d);
		ft_printf("output ft_printf : %d\n", test_d);
		printf("output printf : %d\n", test_d);
		ft_printf("-------------------------------------\n");
		test_d = rand();
		printf("input : %i\n", test_d);
		ft_printf("output ft_printf : %d\n", test_d);
		printf("output printf : %d\n", test_d);
		ft_printf("-------------------------------------\n");
		test_d = rand() * -1;
		printf("input : %i\n", test_d);
		ft_printf("output ft_printf : %d\n", test_d);
		printf("output printf : %d\n", test_d);
		ft_printf("-------------------------------------\n");
		test_d = rand();
		ft_printf("input : %i\n", test_d);
		ft_printf("output ft_printf : %d\n", test_d);
		printf("output printf : %d\n", test_d);
		ft_printf("-------------------------------------\n");
		test_d = -2147483648;
		ft_printf("input : %i\n", test_d);
		ft_printf("output ft_printf : %d\n", test_d);
		printf("output printf : %d\n", test_d);
		ft_printf("-------------------------------------\n");
	}
	else if (argv[1][0] == 'i')
	{
		srand(time(NULL));
		test_d = rand() % 10;
		printf("input : %i\n", test_d);
		ft_printf("output ft_printf : %i\n", test_d);
		printf("output printf : %i\n", test_d);
		ft_printf("-------------------------------------\n");
		test_d = rand();
		printf("input : %i\n", test_d);
		ft_printf("output ft_printf : %i\n", test_d);
		printf("output printf : %i\n", test_d);
		ft_printf("-------------------------------------\n");
		test_d = rand() * -1;
		printf("input : %i\n", test_d);
		ft_printf("output ft_printf : %i\n", test_d);
		printf("output printf : %i\n", test_d);
		ft_printf("-------------------------------------\n");
		test_d = rand();
		ft_printf("input : %i\n", test_d);
		ft_printf("output ft_printf : %i\n", test_d);
		printf("output printf : %i\n", test_d);
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
	else if (argv[1][0] == '%')
	{
		ft_printf("output ft_printf : %%\n");
		printf("output printf : %%\n");
		ft_printf("-------------------------------------\n");
	}
	else if (argv[1][0] == 'p')
	{
		ft_printf("output ft_printf : %p\n", test_p);
		printf("output printf : %p\n", (char *)test_p);
		ft_printf("-------------------------------------\n");
	}
	return (0);	
}		