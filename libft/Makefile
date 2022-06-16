# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaric <mmaric@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 13:54:45 by mmaric            #+#    #+#              #
#    Updated: 2022/06/15 18:58:34 by mmaric           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG = libft.a

SRCS 	= 	ft_strlcpy.c \
		ft_putstr_fd.c \
		ft_strlen.c \
		ft_memcmp.c \
		ft_split.c \
		ft_memcpy.c \
		ft_strnstr.c \
		ft_putchar_fd.c \
		ft_strjoin.c
		
OBJS 	= 	$(SRCS:%.c=%.o)

HEADER	=	-I ./

CC		=	cc
FLAGS 	= 	-Wall -Wextra -Werror -g

.c.o:		%.o : %.c
					@$(CC) ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)
					@echo "\033[33mCompiling libft/$<..."
	
all:		${PROG}

${PROG}: 	 ${OBJS}
					@echo "\n\033[33m----Compiling lib----"
					@ar rc $(PROG) $(OBJS)
					@echo "\n\033[33m$(PROG) created\n"


clean: 
			@echo "\033[33mRemoving $< $(OBJS)..."
			@rm -f $(OBJS)
			
fclean:		
			@echo "\033[33mRemoving $(OBJS) $(PROG)..."
			@rm -f $(OBJS)
			@rm -f $(PROG)

re: fclean all

.PHONY: clean fclean all re