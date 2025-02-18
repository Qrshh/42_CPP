NAME = sed
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp sed.cpp
OBJ = $(SRC:.cpp=.o)
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@printf " - Linking\n"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@printf " - Executable Ready\n"

%.o: %.cpp
	@printf " - Compiling $<\n"
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@printf " - Object Files Removed\n"

fclean: clean
	@$(RM) $(NAME)
	@printf " - Executable Removed\n"

re: fclean all

.PHONY: all clean fclean re