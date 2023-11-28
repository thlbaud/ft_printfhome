# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 13:32:16 by tmouche           #+#    #+#              #
#    Updated: 2023/11/28 17:33:05 by tmouche          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_printf_utils.c

OBJS	:=	$(SRCS:.c=.o)

HEAD	:=	ft_printf.h

CFLAGS	:=	-Wall -Wextra -Werror

AR	:=	ar rcs

NAME	:= libftprintf.a

all		:	$(NAME)

%.o		:	%.c ${HEAD}
	${CC} ${CFLAGS} -c $< -o $@

$(NAME)	:	$(OBJS) Makefile 
			$(AR) $(NAME) $(OBJS)

clean	:
	rm -f $(OBJS) $(B_OBJS)

fclean	:	clean
				rm -f $(NAME)

re	:	fclean all

.PHONY: all clean fclean re