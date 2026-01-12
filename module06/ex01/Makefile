NAME = convert

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

INCLUDES_DIR = include/
INCLUDES = -I $(INCLUDES_DIR)

HEADER_FILES = 
HEADERS = $(addprefix $(INCLUDES_DIR), $(HEADER_FILES))

SRCS_DIR = src/
SRCS_FILES = main.cpp 
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

format:
	clang-format -i $(SRCS) $(HEADERS)

linter:
	clang-tidy $(SRCS) --extra-arg="-I$(INCLUDES_DIR)" -- -std=c++98

re: fclean all

.PHONEY: all clean fclean format linter re
