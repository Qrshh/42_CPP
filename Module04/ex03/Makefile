NAME	=	materia
O		=	obj
I		=	inc
S		=	src
SRC		=	$S/AMateria.cpp \
			$S/Character.cpp \
			$S/Cure.cpp \
			$S/Ice.cpp \
			$S/MateriaSource.cpp \
			$S/main.cpp
INCS	=	$I/AMateria.hpp \
			$I/Character.hpp \
			$I/Cure.hpp \
			$I/Ice.hpp \
			$I/ICharacter.hpp \
			$I/IMateriaSource.hpp \
			$I/MateriaSource.hpp
OBJ		=	$(SRC:$S/%.cpp=$O/%.o)
CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98 -g3 -I$I
LDFLAGS	=

ERASE		=	\033[2K\r
BLUE		=	\033[34m
YELLOW		=	\033[33m
GREEN		=	\033[32m
END			=	\033[0m

all: $(NAME)

$O:
	@mkdir -p $O

$O/%.o: $S/%.cpp Makefile $(INCS) | $O
	$(CC) $(CFLAGS) -c $< -o $@
	printf "$(BLUE)-> $<$(END)\n"

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $(NAME)
	printf "$(GREEN)$(NAME) made$(END)\n"

clean:
	rm -rdf $O
	printf "$(YELLOW)$O removed$(END)\n"

fclean:	clean
	rm -f $(NAME)
	printf "$(YELLOW)$(NAME) removed$(END)\n"

re: fclean all

.PHONY: all clean fclean re
.SILENT:
