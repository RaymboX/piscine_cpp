
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

NAME 			=	RPN
#CPP_LIST-----------------------------------------------------------------------
#  find ./*.cpp -type f | cut -c3- | sed 's/$/ \\/'

SRCS			=	main.cpp \
					RPN.cpp

#HPP_LIST-----------------------------------------------------------------------
#  find ./*.hpp -type f | cut -c3- | sed 's/$/ \\/'

HEADERS			=	colors.hpp \
					RPN.hpp


#PROJECT EXPLANATION------------------------------------------------------------
define EXPLANATION
--------------------------------------------------------------------------------
MODULE 09 _ EX01 _  Reverse Polish Notation
Faire un programme qui prendra en paramêtre un calcul sous forme de Reverse
	polish notation et donner le resultat.
Les nombres sont compris entre 0 et 9 et les opérateurs acceptés sont + - * /.
Un conteneur doit être utiliser différent de celui du dernier exercice.
Calcul normal:           1 + 2
Reverse polish notation: 1 2 +
Pour plus d'information, consutez le pdf. (make pdf)
--------------------------------------------------------------------------------
endef
export EXPLANATION


#TOOLS--------------------------------------------------------------------------
define TOOLS
--------------------------------------------------------------------------------
OUTILS INCLUS DISPONIBLES
make goal		-> Vulgarisation du but de l'exercice
make test		-> Lance des series de test
make demarche		-> Creer un executable qui affiche la démarche
make online		-> Ouvre une page de calculatrice en ligne
make pdf 		-> Ouvre le PDF sujet
make video42		-> Ouvre la page des vidéos CPP sur l'intra
make leak		-> Execute le programme avec "leaks -- atExit -- " en premice
make valgrind		-> Execute le programme avec "valgrind --leak-check=full " en premice
make tools		-> Affiche les outils disponibles (ceci)
--------------------------------------------------------------------------------
endef
export TOOLS

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


#TEST---------------------------------------------------------------------------

TEST_NAME		= 	

#TEST_CPP_LIST
TEST_SRCS		=	

TEST_FILE		=	
TEST_FILE2		=	

#MAINTEST-----------------------------------------------------------------------

#DIRECTORY----------------------------------------------------------------------

OBJS_DIR		= 	./obj

#SYSTEM VAR---------------------------------------------------------------------

CFLAGS 			= 	-Wall -Werror -Wextra
#CFLAGS			+=	-std=c++98
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

all: 	init $(COLORS_FILE) $(DATACSV_FILE) $(NAME)

$(NAME): $(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@echo "$G$(NAME) ready!$W"
			@make goal
			@make tools

$(COLORS_FILE):
			@echo "$$COLORS_FILE_CONTENT" > $(COLORS_FILE)
			@echo "$GJ'$Rai $Yfait $Ccolors$G.$Zhpp$W"

$(DATACSV_FILE):
			@echo "$$DATACSV_CONTENT" > $(DATACSV_FILE)
			@echo "$G$(DATACSV_FILE) created!$W"

init:
			@mkdir -p $(OBJS_DIR)

clean:
			@$(RM) $(OBJS)
			@$(RM) $(OBJS_DIR)
			@echo "$RObjects removed$W"

fclean: clean
			@$(RM) $(NAME)
			@$(RM) $(FILE)
			@$(RM) $(NAME)_debug
			@$(RM) $(NAME)_debug.dSYM
			@$(RM) $(NAME)_demarche
			@$(RM) $(TEST_FILE)
			@$(RM) $(COLORS_FILE)
			@$(RM) $(DATACSV_FILE)
			@echo "$RExecutable $(NAME) deleted$W"

tools:
			@echo "$C$$TOOLS$W"

goal:
			@echo "$C$$EXPLANATION$W"

leak:
			$(LEAK_CMD) ./$(NAME)

online:
			@open https://wisdomsky.github.io/reverse-polish-notation-js-parser/

demarche: all
			@$(CC) -DDEMARCHE=1 $(CFLAGS) $(SRCS) -o $(NAME)_demarche

test: demarche
			@clear
			@echo "$Y####TEST SERIES 1: Basic fonctionnal + demarche tests####$W"
			./$(NAME) "1 1 +"
			./$(NAME)_demarche "1 1 +"
			@echo "$W"
			./$(NAME) "1 1 + "
			./$(NAME)_demarche "1 1 + "
			@echo "$W"
			./$(NAME) "2 4 -"
			./$(NAME)_demarche "2 4 -"
			@echo "$W"
			./$(NAME) "4 2 *"
			./$(NAME)_demarche "4 2 *"
			@echo "$W"
			./$(NAME) "4 2 /"
			./$(NAME)_demarche "4 2 /"
			@echo "\n$Y        press enter to continue....\n$W"
			@read _
			@clear
			@echo "$Y####TEST SERIES 2: Pdf examples + demarche tests####$W"
			./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
			./$(NAME)_demarche "8 9 * 9 - 9 - 9 - 4 - 1 +"
			@echo "$W"
			./$(NAME) "7 7 * 7 -"
			./$(NAME)_demarche "7 7 * 7 -"
			@echo "$W"
			./$(NAME) "1 2 * 2 / 2 * 2 4 - +"
			./$(NAME)_demarche "1 2 * 2 / 2 * 2 4 - +"
			@echo "$W"
			@echo "\n$Y        press enter to continue....\n$W"
			@read _
			@clear
			@echo "$Y####TEST SERIES 2: Argument quantity tests####$W"
			./$(NAME)
			@echo "$W"
			./$(NAME) "1 1 +" "1 1 +"
			@echo "\n$Y        press enter to continue....\n$W"
			@read _
			@clear
			@echo "$Y####TEST SERIES 3: Command format tests####$W"
			./$(NAME) " 1 1 +"
			@echo "$W"
			./$(NAME) "1 1 +  "
			@echo "$W"
			./$(NAME) "11 1 +"
			@echo "$W"
			./$(NAME) "1 1 ++"
			@echo "$W"
			./$(NAME) "1 1 %"
			@echo "$W"
			./$(NAME) "shjkdfjkhsd"
			@echo "$W"
			./$(NAME) "1 e +"
			@echo "\n$Y        press enter to continue....\n$W"
			@read _
			@clear
			@echo "$Y####TEST SERIES 4: Numbers & operators order tests####$W"
			./$(NAME) "+ 1 1"
			@echo "$W"
			./$(NAME) "1 + 1"
			@echo "$W"
			./$(NAME) "1 1 * * 1"
			@echo "\n$Y        press enter to continue....\n$W"
			@read _
			@clear
			@echo "$Y####TEST SERIES 5: Division by 0 tests####$W"
			./$(NAME) "1 0 /"
			@echo "$W"
			./$(NAME) "3 1 1 - /"
			@echo "\n$Y        press enter to continue....\n$W"
			@read _
			@clear
			@echo "$Y####TEST SERIES 6: Finish with remaining numbers####$W"
			./$(NAME) "1 1 1 +"
			@echo "\n$Y        press enter to continue....\n$W"
			@read _
			@clear
			@echo "$Y####TEST SERIES 7: Empty command####$W"
			./$(NAME) ""
			@echo "$Y\n       ####END OF TESTS####$W"
			@echo "\n$Y        press enter to clear....\n$W"
			@read _
			@clear
			


valgrind:
			$(VALGRIND_CMD) ./$(NAME)

pdf:
			@open https://cdn.intra.42.fr/pdf/pdf/79936/en.subject.pdf

video42:
			@open https://elearning.intra.42.fr/tags/38/notions

debug:	fclean
			@$(CC_DEBUG) $(CFLAGS) $(SRCS) -o $(NAME)_debug
			@echo "$YDebbuging executable ready!$W"

re:			fclean all

#PHONY--------------------------------------------------------------------------

.PHONY:				all clean fclean re init goal test art leak debug tools