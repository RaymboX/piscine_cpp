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

NAME 			= harl2_0

#CPP_LIST-----------------------------------------------------------------------
#  find ./*.cpp -type f | cut -c3- | sed 's/$/ \\/'

SRCS			=	main.cpp \
					Harl.cpp
					

#HPP_LIST-----------------------------------------------------------------------
#  find ./*.hpp -type f | cut -c3- | sed 's/$/ \\/'

HEADERS			=	Harl.hpp

#PROJECT EXPLANATION------------------------------------------------------------
define EXPLANATION
--------------------------------------------------------------------------------
MODULE 01 _ EX05 _ HARL 2.0
Le but est d'etre en mesure d'utiliser les pointeurs de fonction membre.
Il faut regarder dans le code et s'assurer que la fonction complain ne comprend
	pas de foret de if et qu'elle utilise un pointeur de fonction.

Le programme doit renvoyer ces messages via 4 fonctions.

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
make art	-> Affiche le ascii art
make tools	-> Affiche les outils disponibles (ceci)
--------------------------------------------------------------------------------
endef
export TOOLS

define ART
       _______ 
     _/       \_ 
    / |       | \ 
   /  |__   __|  \ 
  |__/((o| |o))\__| 
  |      | |      | 
  |\     |_|     /| 
  | \           / | 
   \| /  ___  \ |/ 
    \ | / _ \ | / 
     \_________/ 
      _|_____|_ 
 ____|_________|____ 
/                   \ 
endef
export ART

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
			@echo "$G$$ART$W"
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
			@echo "$RExecutable $(NAME) deleted$W"

goal:
			@echo "$C$$EXPLANATION$W"

tools:
			@echo "$C$$TOOLS$W"

pdf:
			@open https://cdn.intra.42.fr/pdf/pdf/66969/fr.subject.pdf

leak:
			$(LEAK_CMD) ./$(NAME)

art:
			@echo "$G$$ART$W"

test:
			
debug:	fclean
			@$(CC_DEBUG) $(CFLAGS) $(SRCS) -o $(NAME)_debug
			@echo "$YDebbuging executable ready!$W"

re:			fclean all

#PHONY--------------------------------------------------------------------------

.PHONY:				all clean fclean re init goal test art leak