GREEN = `tput setaf 2`
RED = `tput setaf 1`
END = `tput sgr0`

NAME 		= Sully

SRC_NAME	=	Sully.c \

OBJ 			= $(SRC:.c=.o)
KID			= $(NAME)_*

SRC 			= $(SRC_NAME)
RM 				= rm -rf
CC 				= gcc
MEM				= -g -O3 -fsanitize=address

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -Wall -Wextra -Werror $(OBJ) -o $(NAME)
	@echo "$(GREEN)$(NAME) binary is ready !$(END)"

%.o: %.c
	@echo "$(GREEN)Compiling source files to objects $<$ ...$(END)"
	$(CC) -Wall -Wextra -Werror -c $< -o $@

clean:
	$(RM) $(OBJ) $(KID) 1>/dev/null

fclean:		clean
	$(RM) $(NAME) $(KID) 1>/dev/null
	@echo "$(RED)$(NAME) removed$(END)"

re: clean fclean all
