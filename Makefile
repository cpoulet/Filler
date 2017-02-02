# **************************************************************************** #
#                                                                              #
#                                                                              #
#    Makefile                                                   \\             #
#                                                               (o >           #
#    By: cpoulet <cpoulet@student.42.fr>                     \\_//)            #
#                                                             \_/_)            #
#    Created: 2017/01/22 14:13:52 by cpoulet                   _|_             #
#    Updated: 2017/02/02 15:01:09 by cpoulet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cpoulet.filler
FILES = filler.c\
		parser_filler.c\
		jarvis.c\
		segment.c\
		fill_map.c\
		insert_piece.c\

OTHER = srcs/arena.c\
		srcs/print_arena.c\
		srcs/win.c\

SRC_PATH = srcs/
SRC = $(addprefix srcs/,$(FILES))
OBJ = $(FILES:.c=.o)

INCLUDES = -I includes/ -I libft/includes/
LIBS = -L libft/ -lft
FLAGS = -Wall -Wextra -Werror
PPATH = resources/players/.

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft/
	@echo "Compiling libft.a... OK"
	@gcc $(FLAGS) $(OBJ) $(LIBS) -o $(NAME)
	@echo "Compiling cpoulet.filler... OK"
	cp $(NAME) $(PPATH)

%.o : $(SRC_PATH)%.c
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

clean :
	@rm -f $(OBJ)
	@echo "Deleting objects... OK"
	@make clean -C libft/

fclean : clean
	@rm -f $(NAME)
	@make fclean -C libft/

re : fclean all

show.filler : lib
	@gcc $(FLAGS) $(INCLUDES) $(LIBS) $(OTHER) -o $@
	@mv $@ resources/.
	@if [ -a resources/test ]; then echo y | rm resources/test ; fi;

main : lib
	gcc $(FLAGS) $(INCLUDES) $(SRC) main.c $(LIBS)

lib :
	@make -C libft/
	@make clean -C libft/

.PHONY : all clean fclean re
