# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkremen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/24 18:15:35 by vkremen           #+#    #+#              #
#    Updated: 2019/05/07 04:56:54 by oandrosh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COREWAR = corewar

GCC = clang

FLAGS = -Wall -Werror -Wextra

SRC = 	./src/main.c\
		./src/init.c\
		./src/add_bot.c\
		./src/something_useful.c\
		./src/parsing_bot.c\
		./src/start_fight.c\
		./src/start_fight_2.c\
		./src/operations_1.c\
		./src/operations_2.c\
		./src/operations_3.c\
		./src/utils_for_oper.c\
		./src/visual.c\
		./src/visual2.c

OB = $(SRC:%.c=%.o) 

all: $(COREWAR)

%.o:%.c
	@$(GCC) -c $(FLAGS) $< -o $@

$(COREWAR): $(OB)
	@make -C libft
	@$(GCC) $(OB) libft/libft.a -lncurses -o $(COREWAR)

clean: 
	@make clean -C libft
	@rm -f $(OB)

fclean: clean
	@make fclean -C libft
	@rm -f $(COREWAR)

re: fclean all
