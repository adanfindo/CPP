NAME	= phonebook
CC	= clang++
FLAGS	= -std=c++98 -Wall -Wextra -Werror
RM	= rm -f
SRC	= $(wildcard *.cpp)
OBJ	= $(SRC:.cpp=.o)

all: $(NAME)

%.o : %.cpp
	$(CC) $(FLAGS) -c $<

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
