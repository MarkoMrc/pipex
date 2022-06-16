# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaric <mmaric@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 16:03:26 by mmaric            #+#    #+#              #
#    Updated: 2022/06/16 09:30:54 by mmaric           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG 	= 	pipex

SRCS 	= 	srcs/pipex.c srcs/pipex_utils.c srcs/process.c srcs/checkers.c
OBJS 	= 	${SRCS:.c=.o}
MAIN 	= 	srcs/pipex.c 

HEADER 	= 	-Iinclude

CC 		= 	cc
CFLAGS 	= 	-Wall -Wextra -Werror -g 

.c.o: 		%.o : %.c
					@$(CC) ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)
					@echo "\033[33mCompiling $<..."

all:		${PROG}

${PROG}:	${OBJS}
					@make --no-print-directory -C ./libft
					@$(CC) -g ${OBJS} -Llibft -lft -o ${PROG}
					@echo "\033[32mPipex Compiled!\033[0m\n"

clean:		
					@echo "\n\033[31m----Cleaning !----\033[33m\n"
					@make --no-print-directory  clean -C ./libft
					@echo "\033[33mRemoving $< $(OBJS)..."
					@rm -f $(OBJS)
					@echo "\n\033[32m Cleaned !\033[0m\n"

fclean:	
					@echo "\n\033[31m----Cleaning !----\033[33m\n"
					@make --no-print-directory fclean -C ./libft
					@echo "\033[33mRemoving $(OBJS) $(PROG)..."
					@rm -f $(OBJS)
					@rm -f $(NAME)
					@rm -f $(PROG)
					@echo "\n\033[32m All cleaned !\033[0m\n"
		
re:			fclean all

.PHONY: all clean fclean re
