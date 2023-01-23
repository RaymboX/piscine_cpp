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

NAME 			= HarlFilter

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
MODULE 01 _ EX06 _ HARL FILTER
Cette exercice oblige l'utilisation de la function switch.

En utilisant la base de l'ex05, il doit etre maintenant possible de passer
	en argument l'un des niveaux de messages.
Tous les messages avec un niveau egal ou superieur doivent s'afficher.
Les mauvaises entrer sont naturellement filtrees par la function switch.

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
make test	-> Execute une série de tests
make art	-> Affiche le ascii art
make tools	-> Affiche les outils disponibles (ceci)
--------------------------------------------------------------------------------
endef
export TOOLS

define ART
       _______ 
     _/       \_ 
    / |       | \ 
   /  |_/   \_|  \ 
  |__/((o| |o))\__| 
  |      | |      | 
  |\     |_|     /| 
  | \           / | 
   \|    \ /    |/ 
    \    / \    / 
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
			@echo "$Y\nTEST1: No arg$C"
			$(LEAK_CMD) ./$(NAME)
			@echo "$W\n press enter to continue\n"
			@read _
			@echo "$Y\nTEST2: Empty arg$C"
			$(LEAK_CMD) ./$(NAME) ""
			@echo "$W\n press enter to continue\n"
			@read _
			@echo "$Y\nTEST3: DEBUG$C"
			$(LEAK_CMD) ./$(NAME) DEBUG
			@echo "$W\n press enter to continue\n"
			@read _
			@echo "$Y\nTEST4: INFO$C"
			$(LEAK_CMD) ./$(NAME) INFO
			@echo "$W\n press enter to continue\n"
			@read _
			@echo "$Y\nTEST5: WARNING$C"
			$(LEAK_CMD) ./$(NAME) WARNING
			@echo "$W\n press enter to continue\n"
			@read _
			@echo "$Y\nTEST6: ERROR$C"
			$(LEAK_CMD) ./$(NAME) ERROR
			@echo "$W\n press enter to continue\n"
			@read _
			@echo "$Y\nTEST7: Random stuff$C"
			$(LEAK_CMD) ./$(NAME) fdsgsdkjfgh
			@echo "$Y------------------TEST END-----------------\n$W"

			
debug:	fclean
			@$(CC_DEBUG) $(CFLAGS) $(SRCS) -o $(NAME)_debug
			@echo "$YDebbuging executable ready!$W"

re:			fclean all

#PHONY--------------------------------------------------------------------------

.PHONY:				all clean fclean re init goal test art leak