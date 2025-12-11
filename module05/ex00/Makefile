NAME = a.out

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

INCLUDES_DIR = include/
INCLUDES = -I $(INCLUDES_DIR)

HEADER_FILES = Bureaucrat.h
HEADERS = $(addprefix $(INCLUDES_DIR), $(HEADER_FILES))

SRCS_DIR = src/
SRCS_FILES = main.cpp Bureaucrat.cpp
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(INCLUDES_FILES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

format:
	clang-format -i *.h *.cpp

linter:
	clang-tidy *.cpp --extra-arg="isysroot" --extra-arg="$(xcrun --show-sdk-path)" -- -I. -std=c++98

re: fclean all

.PHONEY: clean fclean re all
