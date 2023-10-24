NAME 		= megaphone

CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98 -MMD
RM			= rm -rf

SRC 		= megaphone.cpp
OBJ		 	= $(SRC:.cpp=.o)
DEP 		= $(SRC:.cpp=.d)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "Compilation de " $(NAME) "..."
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "Terminé!"

%.o : %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean : 
	@$(RM) $(OBJ) $(DEP)

fclean : clean
	@$(RM) $(NAME)

re : fclean all