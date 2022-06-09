# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaric <mmaric@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 16:03:26 by mmaric            #+#    #+#              #
#    Updated: 2022/06/02 13:51:23 by mmaric           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG 	= 	pipex

SRCS 	= 	srcs/pipex.c srcs/pipex_utils.c srcs/process.c
OBJS 	= 	${SRCS:.c=.o}
MAIN 	= 	srcs/pipex.c 

HEADER 	= 	-Iinclude

CC 		= 	gcc
CFLAGS 	= 	-Wall -Wextra -Werror -g 

.c.o: 		%.o : %.c 
					@gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)
					@echo "\n\033[33mCompiling $<..."

all:		${PROG}

${PROG}:	${OBJS}
					@echo "\n\033[33m----Compiling lib----\n"
					@make re -C ./libft
					@$(CC) -g ${OBJS} -Llibft -lft -o ${PROG}
					@echo "\n\033[32mPipex Compiled!\033[0m\n"

clean:		
					@echo "\n\033[31m----Cleaning !----\033[33m\n"
					@make clean -C ./libft
					@rm -f $(OBJS)
					@echo "\n\033[32mCleaned !\033[0m\n"

fclean:	
					@echo "\n\033[31m----Cleaning !----\033[33m\n"
					@make fclean -C ./libft
					@rm -f $(OBJS)
					@rm -f $(NAME)
					@rm -f $(PROG)
					@echo "\n\033[32mAll cleaned !\033[0m\n"
		
re:			fclean all

.PHONY: all clean fclean re
