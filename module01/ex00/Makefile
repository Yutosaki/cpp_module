NAME = zombie

INCLUDE_DIR = includes
INCLUDES = -I $(INCLUDE_DIR)

SRCS_DIR = srcs/
SRCS_FILES = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS = $(SRCS:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJS)	-o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) -f $(OBJS)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
