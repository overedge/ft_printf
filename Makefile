# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/14 18:05:20 by nahmed-m          #+#    #+#              #
#    Updated: 2016/01/14 19:34:01 by nahmed-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a


SRC_NAME = ft_printf.c

OBJ_NAME = $(SRC_NAME:.c=.o)


$(NAME) :
	@gcc -Werror -Wextra -Wall $(SRC_NAME) -c
	@make -C libft/ fclean && make -C libft/
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJ_NAME)
	@ranlib $(NAME)
	@echo "\033[1;34m ----LIBFT-PRINTF----- :\033[m \033[1;32m DONE !\033[m"

all : $(NAME)

clean :
	@rm -rf $(OBJ_NAME)
	@make -C libft/ clean
	@echo "\033[1;34m ----LIBFT-PRINTF----- :\033[m \033[1;32m DELETE OBJ FILES !\033[m"

fclean : clean
	@rm -rf $(NAME)
	@make -C libft/ clean
	@echo "\033[1;34m ----LIBFT-PRINTF---- :\033[m \033[1;32m DELETE libftprintf.a !\033[m"

re : fclean all

.PHONY : all clean fclean re
