NAME = a.out

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

INCLUDES_DIR = include/
INCLUDES = -I $(INCLUDES_DIR)

HEADER_FILES = Bureaucrat.h AForm.h presidentialPardonForm.h RobotomyRequesrForm.h ShrubberyCreationForm.h Intern.h
HEADERS = $(addprefix $(INCLUDES_DIR), $(HEADER_FILES))

SRCS_DIR = src/
SRCS_FILES = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
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
