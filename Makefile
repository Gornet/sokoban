NAME   = sokoban 
D_SRC  = ./src/
C_FILE = $(D_SRC)main.c $(D_SRC)map.c $(D_SRC)fonction.c $(D_SRC)deplacement.c

all : $(NAME)

$(NAME) :

	@gcc src/*.c -o $(NAME)
debug :
	@rm $(NAME)
	@gcc src/*.c -o $(NAME) -g
	@gdb $(NAME)
clean :
	@rm $(NAME)

