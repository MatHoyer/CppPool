NAME 		= Bureaucrat

CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98 -MMD
RM			= rm -rf

SRC 		= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
INCLUDE		= Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp
FILE		= .compil/
OBJ		 	= $(SRC:.cpp=.o)
DEP 		= $(SRC:.cpp=.d)
PREFO 		= $(addprefix $(FILE),$(OBJ))
PREFD 		= $(addprefix $(FILE),$(DEP))

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(PREFO)
	@echo "Compilation de " $(NAME) "..."
	@$(CXX) $(CXXFLAGS) $(PREFO) -o $(NAME)
	@echo "Terminé!"

$(FILE) :
	@mkdir -p $(FILE)

$(FILE)%.o : %.cpp | $(FILE)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean : 
	@echo "Suppression des .o et .d..."
	@$(RM) $(FILE)
	@echo "Terminé!"

fclean : clean
	@echo "Suppression de l'executable..."
	@$(RM) $(NAME)
	@echo "Terminé!"

-include $(PREFD)

re : fclean all