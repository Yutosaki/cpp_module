NAME = a.out

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDES_DIR = includes/
INCLUDES = -I $(INCLUDES_DIR)

SRCS_DIR = srcs/
SRCS_FILE = main.cpp Fixed.cpp
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILE))

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re