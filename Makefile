# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 13:32:16 by tmouche           #+#    #+#              #
#    Updated: 2023/11/26 14:08:02 by tmouche          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 

OBJS	:=	$(SRCS:%.c=%.o)

HEAD	:=	libftprintf.h

CFLAGS	:=	-Wall -Wextra -Werror

AR	:=	ar rcs

NAME	:=	libftprintf.a

all		:	$(NAME)

$(NAME)	:	$(OBJS) Makefile $(HEAD)
			$(AR) -o $(NAME) $(OBJS)

clean	:
	$(RM) -f $(OBJS) $(B_OBJS)

fclean	:	clean
				$(RM) $(NAME)

re	:	fclean all

.PHONY: all clean fclean re
