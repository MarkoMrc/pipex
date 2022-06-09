# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaric <mmaric@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 13:54:45 by mmaric            #+#    #+#              #
#    Updated: 2022/06/01 14:30:59 by mmaric           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

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

	
all: $(NAME)

.SILENT :
$(NAME):  $(SRCS)
			gcc $(FLAGS) -c $(SRCS) -I ./
			ar rc $(NAME) $(OBJS)


clean: 
		rm -f $(OBJS) 
fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re