
#\\           //#
# \\         // #
# |\\       //| #
# ||\\     //|| #
# || RAYMBOX || #		MAKEFILE
# ||//     \\|| #		PISCINE CPP FORMAT
# |//       \\| #
# //         \\ #
#//           \\#

#PROGRAM NAME-------------------------------------------------------------------

NAME 			=	span
#CPP_LIST-----------------------------------------------------------------------
#  find ./*.cpp -type f | cut -c3- | sed 's/$/ \\/'

SRCS			=	main.cpp \
					Span.cpp


#HPP_LIST-----------------------------------------------------------------------
#  find ./*.hpp -type f | cut -c3- | sed 's/$/ \\/'

HEADERS			=	colors.hpp \
					Span.hpp

#COLORS FILE--------------------------------------------------------------------
COLORS_FILE = colors.hpp

define COLORS_FILE_CONTENT
#pragma once
#ifndef COLORS_HPP
# define COLORS_HPP

# define COLORDEF "\033[0m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define CYAN "\033[1;34m"
# define PURPLE "\033[1;35m"
# define BLUE "\033[1;36m"
# define WHITE "\033[1;37m"

#endif
endef
export COLORS_FILE_CONTENT
#-------------------------------------------------------------------------------

#PROJECT EXPLANATION------------------------------------------------------------
define EXPLANATION
--------------------------------------------------------------------------------
MODULE 08 _ EX01 _ SPAN
(Utiliser la STL au maximum)

Créer une classe Span qui pourra stocker maximum N int.
Elle devra contenir les fonctions
- addNumber: Ajoute un nombre au container et renvoie une exception si over limit
- shortestSpan: retourne la plus petite distance entre deux nombres
- longuestSpan: retourne la plus grande distance entre deux nombres
	pour les deux fonctions
	- c'est le span pour n'importequelle chiffre et non le span entre les entiers
		adjacent de la liste
	- Renvoie une exception si aucune ou une donnée présente dans la liste

--------------------------------------------------------------------------------
endef
export EXPLANATION


#TOOLS--------------------------------------------------------------------------
define TOOLS
--------------------------------------------------------------------------------
OUTILS INCLUS DISPONIBLES
make goal		-> Vulgarisation du but de l'exercice
make pdf 		-> Ouvre le PDF sujet
make video42		-> Ouvre la page des vidéos CPP sur l'intra
make leak		-> Execute le programme avec "leaks -- atExit -- " en premice
make valgrind		-> Execute le programme avec "valgrind --leak-check=full " en premice
make tools		-> Affiche les outils disponibles (ceci)
--------------------------------------------------------------------------------
endef
export TOOLS

#TEST---------------------------------------------------------------------------

TEST_NAME		= 	

#TEST_CPP_LIST
TEST_SRCS		=	

TEST_FILES		=	

#MAINTEST-----------------------------------------------------------------------



#DIRECTORY----------------------------------------------------------------------

OBJS_DIR		= 	./obj

#SYSTEM VAR---------------------------------------------------------------------

CFLAGS 			= 	-Wall -Werror -Wextra -std=c++98
CC				= 	g++
CC_DEBUG		=	g++ -g

RM				= 	rm -rf
LEAK_CMD		=	leaks --atExit --
VALGRIND_CMD	=	valgrind --leak-check=full


R = $(shell tput -Txterm setaf 1)
G = $(shell tput -Txterm setaf 2)
W = $(shell tput -Txterm setaf 7)
C = $(shell tput -Txterm setaf 6)
Y = $(shell tput -Txterm setaf 3)
Z = $(shell tput -Txterm setaf 5)

#OBJ----------------------------------------------------------------------------

OBJS 			= 	$(SRCS:%.cpp=$(OBJS_DIR)/%.o)

$(OBJS_DIR)/%.o:%.cpp $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

#RULES--------------------------------------------------------------------------

all: 	init colors $(NAME)

$(NAME): $(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@echo "$G$(NAME) ready!$W"
			@make goal
			@make tools
			
init:
			@mkdir -p $(OBJS_DIR)

colors: $(COLORS_FILE)

$(COLORS_FILE):
			@echo "$$COLORS_FILE_CONTENT" > $(COLORS_FILE)
			@echo "$GJ'$Rai $Yfait $Ccolors$G.$Zhpp$W"

clean:
			@$(RM) $(OBJS)
			@$(RM) $(OBJS_DIR)
			@echo "$RObjects removed$W"

fclean: clean
			@$(RM) $(NAME)
			@$(RM) $(FILE)
			@$(RM) $(NAME)_debug
			@$(RM) $(NAME)_debug.dSYM
			@$(RM) $(TEST_FILES)
			@$(RM) $(COLORS_FILE)
			@echo "$RExecutable $(NAME) deleted$W"

tools:
			@echo "$C$$TOOLS$W"

goal:
			@echo "$C$$EXPLANATION$W"

leak:
			$(LEAK_CMD) ./$(NAME)

test:
			

valgrind:
			$(VALGRIND_CMD) ./$(NAME)

pdf:
			@open https://cdn.intra.42.fr/pdf/pdf/58245/fr.subject.pdf

video42:
			@open https://elearning.intra.42.fr/tags/38/notions

debug:	fclean colors
			@$(CC_DEBUG) $(CFLAGS) $(SRCS) -o $(NAME)_debug
			@echo "$YDebbuging executable ready!$W"

re:			fclean all

#PHONY--------------------------------------------------------------------------

.PHONY:				all clean fclean re init goal test art leak debug tools