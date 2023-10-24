NAME 		= PhoneBook

CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98 -MMD
RM			= rm -rf

SRC 		= main.cpp Contact.cpp PhoneBook.cpp
INCLUDE		= Contact.hpp PhoneBook.hpp
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
	@echo "Suppression des .o et .d..."
	@$(RM) $(OBJ) $(DEP)
	@echo "Terminé!"

fclean : clean
	@echo "Suppression de l'executable..."
	@$(RM) $(NAME)
	@echo "Terminé!"

-include $(DEP)

re : fclean all