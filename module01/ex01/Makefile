NAME = zombieHorde

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -stdlib=libc++

INCLUDE_DIR = includes
INCLUDES = -I $(INCLUDE_DIR)

SRCS_DIR = srcs
SRCS_FILES = main.cpp Zombie.cpp zombieHorde.cpp
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) -f $(OBJS)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re