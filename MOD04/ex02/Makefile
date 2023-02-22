
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

NAME 			= Aabstrait

#CPP_LIST-----------------------------------------------------------------------
#  find ./*.cpp -type f | cut -c3- | sed 's/$/ \\/'

SRCS			=	main.cpp \
					AAnimal.cpp \
					Dog.cpp \
					Cat.cpp \
					WrongAAnimal.cpp \
					WrongCat.cpp \
					Brain.cpp

#HPP_LIST-----------------------------------------------------------------------
#  find ./*.hpp -type f | cut -c3- | sed 's/$/ \\/'

HEADERS			=	AAnimal.hpp \
					Dog.hpp \
					Cat.hpp \
					WrongAAnimal.hpp \
					WrongCat.hpp \
					Brain.hpp

#PROJECT EXPLANATION------------------------------------------------------------
define EXPLANATION
--------------------------------------------------------------------------------
MODULE 04 _ EX02 _ CLASSE ABSTRAITE

En réutilisant les fichiers du dernier exercice, faire de la classe Animal une
	classe abstraite soit en
	- Faisant de la fonction makeSound ne fonction virtuel pure (virtual et = 0)

Ensuite le code doit fonctionner comme avant donc, le main n'a pas été modifier
	à l'exception du nom de la classe Animal qui est maintenant AAnimal 
	(A pour abstraite)

- Toute les classe appelant Animal appel maintenant AAnimal
- Le comportement de la fonction makeSound de la classe AAnimal à été effacée

- Un exemple //mute d'instanciation de la classe AAnimal est dans le main pour
	démontrer qu'il n'est plus possible d'instacier cette classe.

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

tools:
			@echo "$C$$TOOLS$W"

goal:
			@echo "$C$$EXPLANATION$W"

leak:
			$(LEAK_CMD) ./$(NAME)

valgrind:
			$(VALGRIND_CMD) ./$(NAME)

pdf:
			@open https://cdn.intra.42.fr/pdf/pdf/58235/fr.subject.pdf

debug:	fclean
			@$(CC_DEBUG) $(CFLAGS) $(SRCS) -o $(NAME)_debug
			@echo "$YDebbuging executable ready!$W"

re:			fclean all

#PHONY--------------------------------------------------------------------------

.PHONY:				all clean fclean re init goal test art leak