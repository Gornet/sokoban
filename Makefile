NAME   	= sokoban 
SRC  	= src/
C_FILE 	= $(SRC)main.c $(SRC)afficher_tableau.c $(SRC)deplacement.c $(SRC)fontion.c  
C_FILE += $(SRC)ft_check_extension.c $(SRC)ft_check_location.c $(SRC)ft_read_file.c  
C_FILE += $(SRC)ft_sokoban.c $(SRC)ft_strlen.c
 

all : $(NAME)

$(NAME) :

	@gcc $(C_FILE) -o $(NAME)
test	:
	@gcc $(C_FILE) $(SRC)map.c -o $(NAME)
debug	:
	@rm $(NAME)
	@gcc $(C_FILE) -o $(NAME) -g
	@gdb $(NAME)
clean 	:
	@rm $(NAME)

