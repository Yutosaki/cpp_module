NAME = a.out

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDES_DIR = includes/
INCLUDES = -I $(INCLUDES_DIR)

HEADER_FILES = ClapTrap.hpp
HEADERS = $(addprefix $(INCLUDES_DIR), $(HEADER_FILES))

SRCS_DIR = srcs/
SRCS_FILES = main.cpp ClapTrap.cpp
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re