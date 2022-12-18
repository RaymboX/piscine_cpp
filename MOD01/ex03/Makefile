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

NAME 			= violence

#CPP_LIST-----------------------------------------------------------------------
#  find ./*.cpp -type f | cut -c3- | sed 's/$/ \\/'

SRCS			=	main.cpp \
					Weapon.cpp \
					HumanA.cpp \
					HumanB.cpp
					

#HPP_LIST-----------------------------------------------------------------------
#  find ./*.hpp -type f | cut -c3- | sed 's/$/ \\/'

HEADERS			=	Weapon.hpp \
					HumanA.hpp \
					HumanB.hpp

#PROJECT EXPLANATION------------------------------------------------------------
define EXPLANATION
--------------------------------------------------------------------------------
MODULE 01 _ EX03 _ VIOLENCE INUTILE
Faire trois classes
- Weapon avec deux fonctions (get et set type)
- HumanA: Prend une arme comme parametre (reference)
- HumanB: Pas toujours d'arme en parametre (pointeur)

En utilisant le main inclut dans le sujet, le programme devrait
	afficher deux attaques par humain avec des armes differentes.

Add on
- J'ai ajouter une attaque sans arme avec jim afin de demontrer l'attaque
	lorsqu'il ne possede pas d'arme. (Class HumanB)
--------------------------------------------------------------------------------
endef
export EXPLANATION

define ART
                        ____________ 
                      .~      ,   . ~. 
                     /                \ 
                    /      /~\/~\   ,  \ 
                   |   .   \    /   '   | 
                   |         \/         | 
          XX       |  /~~\        /~~\  |       XX 
        XX  X      | |  o  \    /  o  | |      X  XX 
      XX     X     |  \____/    \____/  |     X     XX 
 XXXXX     XX      \         /\        ,/      XX     XXXXX 
X        XX%;;@      \      /  \     ,/      @%%;XX        X 
X       X  @%%;;@     |           '  |     @%%;;@  X       X 
X      X     @%%;;@   |. ` ; ; ; ;  ,|   @%%;;@     X      X 
 X    X        @%%;;@                  @%%;;@        X    X 
  X   X          @%%;;@              @%%;;@          X   X 
   X  X            @%%;;@          @%%;;@            X  X 
    XX X             @%%;;@      @%%;;@             X XX 
      XXX              @%%;;@  @%%;;@              XXX 
                         @%%;;%%;;@ 
                           @%%;;@ 
                         @%%;;@..@@ 
                          @@@  @@@ 
endef
export ART

#DIRECTORY----------------------------------------------------------------------

OBJS_DIR		= 	./obj

#SYSTEM VAR---------------------------------------------------------------------

CFLAGS 			= 	-Wall -Werror -Wextra -std=c++98
CC				= 	g++

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
			
init:
			@mkdir -p $(OBJS_DIR)

clean:
			@$(RM) $(OBJS)
			@$(RM) $(OBJS_DIR)
			@echo "$RObjects removed$W"

fclean: clean
			@$(RM) $(NAME)
			@echo "$RExecutable $(NAME) deleted$W"

goal:
			@echo "$C$$EXPLANATION$W"

leak:
			$(LEAK_CMD) ./$(NAME)

art:
			@echo "$G$$ART$W"

test:
			

re:			fclean all

#PHONY--------------------------------------------------------------------------

.PHONY:				all clean fclean re init goal test