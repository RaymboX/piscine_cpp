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

NAME 			= weCanTalk

#CPP_LIST-----------------------------------------------------------------------
#  find ./*.cpp -type f | cut -c3- | sed 's/$/ \\/'

SRCS			=	main.cpp \
					Fixed.cpp
					

#HPP_LIST-----------------------------------------------------------------------
#  find ./*.hpp -type f | cut -c3- | sed 's/$/ \\/'

HEADERS			=	Fixed.hpp

#PROJECT EXPLANATION------------------------------------------------------------
define EXPLANATION
--------------------------------------------------------------------------------
MODULE 02 _ EX02 _ MAINTENANT, ON PEUT PARLER
A partir du dernier exercice, ajouter ceci

- 6 operateurs de comparaison: >, <, >=, <=, ==, et !=.
- 4 operateurs de arithmetique: +, -, * et /.
- 4 operateurs d'incrementation et decrementation (pre/post pour chaque)
- Deux fonctions membre --min-- ayant deux instances de la classe Fixed en parametre
 	(non constant pour une et const pour l'autre) retournant le plus petit des deux.
- Deux fonctions membre --max-- ayant deux instances de la classe Fixed en parametre
 	(non constant pour une et const pour l'autre) retournant le plus grand des deux.

Ensuite, en executant le main inclu dans le sujet, le resultat doit etre 
	identique a ce qui est presenter dans le pdf
--------------------------------------------------------------------------------
endef
export EXPLANATION


#TOOLS--------------------------------------------------------------------------
define TOOLS
--------------------------------------------------------------------------------
OUTILS INCLUS DISPONIBLES
make goal	-> Vulgarisation du but de l'exercice
make pdf 	-> Ouvre le PDF sujet
make leak	-> Execute le programme avec "leaks -- atExit -- " en premice
make test	-> Creer un nouveau main et execute ce main avec la meme classe
make tools	-> Affiche les outils disponibles (ceci)
--------------------------------------------------------------------------------
endef
export TOOLS

#TEST---------------------------------------------------------------------------

TEST_NAME		= 	mod02_ex02_test

#TEST_CPP_LIST
TEST_SRCS		=	main_test.cpp \
					Fixed.cpp

TEST_FILES		=	main_test.cpp \
					mod02_ex02_test

#MAINTEST-----------------------------------------------------------------------
define MAINTEST
#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed a(42.42f);
	Fixed const b(100);
	Fixed c (-123.456f);
	Fixed d (-22);
	
	std::cout << "VALUES-----------------" << std::endl;
	std::cout << "a:         " << a << std::endl;
	std::cout << "b:         " << b << std::endl;
	std::cout << "c:         " << c << std::endl;
	std::cout << "d:         " << d << std::endl << std::endl;
	
	std::cout << "ITERATION--------------" << std::endl;
	std::cout << "++a:       " << ++a << std::endl;
	std::cout << "a:         " << a << std::endl;
	std::cout << "a++:       " << a++ << std::endl;
	std::cout << "a:         " << a << std::endl;
	std::cout << "--a:       " << --a << std::endl;
	std::cout << "a:         " << a << std::endl;
	std::cout << "a--:       " << a-- << std::endl;
	std::cout << "a:         " << a << std::endl << std::endl;

	std::cout << "OPERATION--------------" << std::endl;
	std::cout << "a + b:     " << a + b << std::endl;
	std::cout << "a:         " << a << std::endl;
	std::cout << "a - b:     " << a - b << std::endl;
	std::cout << "a:         " << a << std::endl;
	std::cout << "a * b:     " << a * b << std::endl;
	std::cout << "a:         " << a << std::endl;
	std::cout << "a / b:     " << a / b << std::endl;
	std::cout << "a:         " << a << std::endl;
	std::cout << "a / 0:     " << a / 0 << std::endl << std::endl;

	std::cout << "COMPARATEUR-------------" << std::endl;
	std::cout << "a == b:    " << (a == b) << std::endl;
	std::cout << "a > b:     " << (a > b) << std::endl;
	std::cout << "a < b:     " << (a < b) << std::endl;
	std::cout << "a >= b:    " << (a >= b) << std::endl;
	std::cout << "a <= b:    " << (a <= b) << std::endl << std::endl;

	std::cout << "MAX_MIN FUNCTION--------" << std::endl;
	std::cout << "max(a, b): " << Fixed::max( a, b ) << std::endl;
	std::cout << "min(a, b): " << Fixed::min( a, b ) << std::endl << std::endl;
	
	return 0;
}	
endef
export MAINTEST


#DIRECTORY----------------------------------------------------------------------

OBJS_DIR		= 	./obj

#SYSTEM VAR---------------------------------------------------------------------

CFLAGS 			= 	-Wall -Werror -Wextra -std=c++98
CC				= 	g++
CC_DEBUG		=	g++ -g

RM				= 	rm -rf
LEAK_CMD		=	leaks --atExit --

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

all: 	init $(NAME)


$(NAME): $(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@echo "$G$(NAME) ready!$W"
			@make goal
			@make tools
			
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
			@$(RM) $(TEST_FILES)
			@echo "$RExecutable $(NAME) deleted$W"

test:
			@echo "$$MAINTEST" > main_test.cpp
			@$(CC) $(CFLAGS) $(TEST_SRCS) -o $(TEST_NAME)
			@./mod02_ex02_test

tools:
			@echo "$C$$TOOLS$W"

goal:
			@echo "$C$$EXPLANATION$W"

leak:
			$(LEAK_CMD) ./$(NAME)

pdf:
			@open https://cdn.intra.42.fr/pdf/pdf/66965/fr.subject.pdf
			
debug:	fclean
			@$(CC_DEBUG) $(CFLAGS) $(SRCS) -o $(NAME)_debug
			@echo "$YDebbuging executable ready!$W"

re:			fclean all

#PHONY--------------------------------------------------------------------------

.PHONY:				all clean fclean re init goal test art leak