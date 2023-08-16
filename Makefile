# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdeniz <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 23:15:03 by hdeniz            #+#    #+#              #
#    Updated: 2023/06/18 14:47:49 by hdeniz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc
# [COMPILER]

CLIENT			=	client.c
SERVER			=	server.c
BONUS_CLEINT	=	client_bonus.c
BONUS_SERVER	=	server_bonus.c
# [MAIN PRODUCT(S) TO COMPILE]

FLAGS			=	-Wall -Wextra -Werror
# [LIBRARY FLAGS]

$(CLIENT): main
$(SERVER): main
a: main
all: main
main:
	@echo ""
	@$(CC) $(CLIENT) $(FLAGS) -o $(CLIENT:.c=) && echo " $(shell tput setab 2)$(shell tput setaf 15)$(CLIENT) Done !$(shell tput sgr0)" && echo ""
	@$(CC) $(SERVER) $(FLAGS) -o $(SERVER:.c=) && echo " $(shell tput setab 2)$(shell tput setaf 15)$(SERVER) Done !$(shell tput sgr0)" && echo ""

b: bonus
bonus:
	@echo ""
	@$(CC) $(BONUS_CLEINT) $(FLAGS) -o $(BONUS_CLEINT:.c=) && echo " $(shell tput setab 2)$(shell tput setaf 15)$(BONUS_CLEINT) Done !$(shell tput sgr0)" && echo ""
	@$(CC) $(BONUS_SERVER) $(FLAGS) -o $(BONUS_SERVER:.c=) && echo " $(shell tput setab 2)$(shell tput setaf 15)$(BONUS_SERVER) Done !$(shell tput sgr0)" && echo ""

c: clean
clear: clean
clean:
	@rm -f $(CLIENT:.c=) && echo "" && echo " $(shell tput setab 1)$(shell tput setaf 11)$(CLIENT:.c=)$(shell tput setaf 15) deleted$(shell tput sgr0)"
	@rm -f $(SERVER:.c=) && echo "" && echo " $(shell tput setab 1)$(shell tput setaf 11)$(SERVER:.c=)$(shell tput setaf 15) deleted$(shell tput sgr0)"

fc: fclean
fclear: fclean
fclean: clean
	@rm -f $(BONUS_CLEINT:.c=) && echo "" && echo " $(shell tput setab 1)$(shell tput setaf 11)$(BONUS_CLEINT:.c=)$(shell tput setaf 15) deleted$(shell tput sgr0)"
	@rm -f $(BONUS_SERVER:.c=) && echo "" && echo " $(shell tput setab 1)$(shell tput setaf 11)$(BONUS_SERVER:.c=)$(shell tput setaf 15) deleted$(shell tput sgr0)"
	@echo ""

r: fclean all
re: fclean all

.PHONY: all a clean clear c fclean fclear fc re r main bonus b
