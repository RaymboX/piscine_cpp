
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

NAME 			= dontBurnTheBeds

#CPP_LIST-----------------------------------------------------------------------
#  find ./*.cpp -type f | cut -c3- | sed 's/$/ \\/'

SRCS			=	main.cpp \
					Animal.cpp \
					Dog.cpp \
					Cat.cpp \
					WrongAnimal.cpp \
					WrongCat.cpp \
					Brain.cpp

#HPP_LIST-----------------------------------------------------------------------
#  find ./*.hpp -type f | cut -c3- | sed 's/$/ \\/'

HEADERS			=	Animal.hpp \
					Dog.hpp \
					Cat.hpp \
					WrongAnimal.hpp \
					WrongCat.hpp \
					Brain.hpp

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
MODULE 04 _ EX01 _ JE NE VEUX PAS BRULER LE MONDE

En réutilisant les fichiers du dernier exercice,
- ajouter une classe Brain ayant comme attribut un array de std::string de 100 ideas
- ajouter un attribut Brain* dans la classe Dog et Cat 
		(dont les constructeurs devront créer le brain via new Brain
		et naturellement être détruit dans le destructeur)

La partie mandatoire du main devra créer un tableau d'Animals dont
- la première moitié des Dog
- la deuxième moitié des Cat
(sera un tableau de 4 animals dont 2 Dog et 2 Cat)
Ensuite, ceux-ci doivent être supprimer en tant qu'Animal 
(soit chaque element du tableau d'Animal)

La copie d'un objet Dog ou Cat doit être profonde (création d'un nouvelle espace mémoire)
	et non superficiel (copie des pointeurs ou références)

La partie homemade démontrera une série de tests démontrant
- L'ordre de création des classes par défaut
- L'utilisation de la fonction makeSound membre de la classe Animal démontrant
		l'utilisation d'objet Animal
- L'ajout et la récupération d'idées dans le brain de chaque Animal
- La création d'une copie de chaque animals
- Modification de l'idée du parent
- La récupération de l'idée ajouté dans le 'parent' a partir de la copie
	(démonstration de la copie profonde)
- L'ordre d'appel des destructeurs
--------------------------------------------------------------------------------
endef
export EXPLANATION


#TOOLS--------------------------------------------------------------------------
define TOOLS
--------------------------------------------------------------------------------
OUTILS INCLUS DISPONIBLES
make goal		-> Vulgarisation du but de l'exercice
make pdf 		-> Ouvre le PDF sujet
make leak		-> Execute le programme avec "leaks -- atExit -- " en premice
make valgrind		-> Execute le programme avec "valgrind --leak-check=full " en premice
make tools		-> Affiche les outils disponibles (ceci)
make howcanwesleep 	-> You'll see.
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
			@$(RM) $(COLORS_FILE)
			@$(RM) $(TEST_FILES)
			@echo "$RExecutable $(NAME) deleted$W"

tools:
			@echo "$C$$TOOLS$W"

goal:
			@echo "$C$$EXPLANATION$W"

leak:
			$(LEAK_CMD) ./$(NAME)

valgrind:
			$(VALGRIND_CMD) ./$(NAME)

howcanwesleep:
			@open https://youtu.be/ejorQVy3m8E

pdf:
			@open https://cdn.intra.42.fr/pdf/pdf/58235/fr.subject.pdf

debug:	fclean
			@$(CC_DEBUG) $(CFLAGS) $(SRCS) -o $(NAME)_debug
			@echo "$YDebbuging executable ready!$W"

re:			fclean all

#PHONY--------------------------------------------------------------------------

.PHONY:				all clean fclean re init goal test art leak colors