NAME = weapon

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDE_DIR = includes/
INCLUDES = -I $(INCLUDE_DIR)

SRCS_DIR = srcs/
SRCS_FILES = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
