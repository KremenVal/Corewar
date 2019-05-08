# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/06 13:32:19 by kbakhari          #+#    #+#              #
#    Updated: 2019/05/08 13:34:33 by kbakhari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COREWAR = asmMY

FLAGS = -Wall -Werror -Wextra

SRC = 	./main.c\
		./utility.c\
		./ft_write.c\
		./ft_functions.c

OB = $(SRC:%.c=%.o) 

all: $(COREWAR)

%.o:%.c
	@gcc -c $(FLAGS) $< -o $@

$(COREWAR): $(OB)
	@make -C ../../libft
	@gcc $(OB) ../../libft/libft.a -lncurses -o $(COREWAR)

clean: 
	@make clean -C ../../libft
	@rm -f $(OB)

fclean: clean
	@make fclean -C ../../libft
	@rm -f $(COREWAR)

re: fclean all
