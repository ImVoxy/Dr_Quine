GREEN = `tput setaf 2`
RED = `tput setaf 1`
END = `tput sgr0`

NAME1 		= Colleen

SRC_NAME1	=	Colleen.c \

OBJ1 			= $(SRC1:.c=.o)

SRC1 			= $(SRC_NAME1)
RM 				= rm -rf
CC 				= gcc
MEM				= -g -O3 -fsanitize=address

all:	$(NAME1) $(NAME2) $(NAME3)

$(NAME1): $(OBJ1)
	$(CC) -Wall -Wextra -Werror $(OBJ1) -o $(NAME1)
	@echo "$(GREEN)$(NAME1) binary is ready !$(END)"

%.o: %.c
	@echo "$(GREEN)Compiling source files to objects $<$ ...$(END)"
	$(CC) -Wall -Wextra -Werror -c $< -o $@

clean:
	$(RM) $(OBJ1)  1>/dev/null

fclean:		clean
	$(RM) $(NAME1)  1>/dev/null
	@echo "$(RED)$(NAME1)  removed$(END)"

re: clean fclean all
