NAME = sed

INCLUDE_DIR = includes/
INCLUDES = -I $(INCLUDE_DIR)

SRC_DIR = srcs/
SRC_FILES = main.cpp replace.cpp
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJS = $(SRCS:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -stdlib=libc++

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