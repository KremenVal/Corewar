# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkremen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/24 18:15:35 by vkremen           #+#    #+#              #
#    Updated: 2019/01/12 18:57:17 by vkremen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COREWAR = corewar

FLAGS = -Wall -Werror -Wextra

SRC = 	./src/main.c\
		./src/init.c\
		./src/add_bot.c\
		./src/something_useful.c\
		./src/bot_validation.c\
		./src/parsing_bot.c\
		./src/start_fight.c\
		./src/helpful_functions.c\
		./src/print.c

OB = $(SRC:%.c=%.o) 

all: $(COREWAR)

%.o:%.c
	@gcc -c $(FLAGS) $< -o $@

$(COREWAR): $(OB)
	@make -C libft
	@gcc $(OB) libft/libft.a -o $(COREWAR)

clean: 
	@make clean -C libft
	@rm -f $(OB)

fclean: clean
	@make fclean -C libft
	@rm -f $(COREWAR)

re: fclean all
