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
make tools	-> Affiche les outils disponibles (ceci)
--------------------------------------------------------------------------------
endef
export TOOLS


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
			@echo "$RExecutable $(NAME) deleted$W"

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