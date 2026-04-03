
NAME=xasmp

src=main.cpp ./table/table.cpp ./table/cel.cpp

NAME = xasmp

SRC = main.cpp ./table/table.cpp ./table/cel.cpp ./character/character.cpp ./character/part.cpp
OBJ = $(SRC:.cpp=.o)

CXX = c++
CXXFLAGS = -g -Wall -Wextra -Werror
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all