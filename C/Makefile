GREEN = `tput setaf 2`
RED = `tput setaf 1`
END = `tput sgr0`

NAME1 		= Colleen
NAME2 		= Grace
NAME3 		= Sully

SRC_NAME1	=	Colleen.c \

SRC_NAME2	=	Grace.c \

SRC_NAME3	=	Sully.c \

OBJ1 			= $(SRC1:.c=.o)
OBJ2 			= $(SRC2:.c=.o)
OBJ3 			= $(SRC3:.c=.o)
KID2			= $(NAME2)_*
KID3			= $(NAME3)_*

SRC1 			= $(SRC_NAME1)
SRC2 			= $(SRC_NAME2)
SRC3 			= $(SRC_NAME3)
RM 				= rm -rf
CC 				= gcc
MEM				= -g -O3 -fsanitize=address

all:	$(NAME1) $(NAME2) $(NAME3)

$(NAME1): $(OBJ1)
	$(CC) -Wall -Wextra -Werror $(OBJ1) -o $(NAME1)
	@echo "$(GREEN)$(NAME1) binary is ready !$(END)"

$(NAME2): $(OBJ2)
	$(CC) -Wall -Wextra -Werror $(OBJ2) -o $(NAME2)
	@echo "$(GREEN)$(NAME2) binary is ready !$(END)"

$(NAME3): $(OBJ3)
	$(CC) -Wall -Wextra -Werror $(OBJ3) -o $(NAME3)
	@echo "$(GREEN)$(NAME3) binary is ready !$(END)"

%.o: %.c
	@echo "$(GREEN)Compiling source files to objects $<$ ...$(END)"
	$(CC) -Wall -Wextra -Werror -c $< -o $@

clean:
	$(RM) $(OBJ1) $(OBJ2) $(OBJ3) $(KID2) $(KID3) 1>/dev/null

fclean:		clean
	$(RM) $(NAME1) $(NAME2) $(NAME3) $(KID2) $(KID3) 1>/dev/null
	@echo "$(RED)$(NAME1) $(NAME2) $(NAME3) removed$(END)"

re: clean fclean all
