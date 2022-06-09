# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaric <mmaric@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 13:54:45 by mmaric            #+#    #+#              #
#    Updated: 2022/06/09 13:37:43 by mmaric           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG = libft.a

SRCS = ft_strlcpy.c \
		ft_putstr_fd.c \
		ft_strlen.c \
		ft_memcmp.c \
		ft_split.c \
		ft_memcpy.c \
		ft_strnstr.c \
		ft_putchar_fd.c \
		ft_strjoin.c \
		
OBJS = $(SRCS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

	
all: $(PROG)

.SILENT :
$(PROG):  $(SRCS)
			@echo "\n\033[33m----Compiling lib----\n"
			gcc $(FLAGS) -c $(SRCS) -I ./
			ar rc $(PROG) $(OBJS)


clean: 
		rm -f $(OBJS) 
fclean: clean
		rm -f $(PROG)

re: fclean all

.PHONY: clean fclean all re