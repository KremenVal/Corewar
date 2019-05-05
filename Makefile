# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkremen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/24 18:15:35 by vkremen           #+#    #+#              #
#    Updated: 2019/05/05 06:35:38 by oandrosh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COREWAR = corewar

FLAGS = -Wall -Werror -Wextra

SRC = 	./src/main.c\
		./src/init.c\
		./src/add_bot.c\
		./src/something_useful.c\
		./src/parsing_bot.c\
		./src/start_fight.c\
		./src/helpful_functions.c\
		./src/print.c\
		./src/visual.c

OB = $(SRC:%.c=%.o) 

all: $(COREWAR)

%.o:%.c
	@gcc -c $(FLAGS) $< -o $@

$(COREWAR): $(OB)
	@make -C libft
	@gcc $(OB) libft/libft.a -lncurses -o $(COREWAR)

clean: 
	@make clean -C libft
	@rm -f $(OB)

fclean: clean
	@make fclean -C libft
	@rm -f $(COREWAR)

re: fclean all
