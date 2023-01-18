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

NAME 			= BSP

#CPP_LIST-----------------------------------------------------------------------
#  find ./*.cpp -type f | cut -c3- | sed 's/$/ \\/'

SRCS			=	main.cpp \
					Fixed.cpp \
					Point.cpp \
					bsp.cpp
					

#HPP_LIST-----------------------------------------------------------------------
#  find ./*.hpp -type f | cut -c3- | sed 's/$/ \\/'

HEADERS			=	Fixed.hpp \
					Point.hpp

#PROJECT EXPLANATION------------------------------------------------------------
define EXPLANATION
--------------------------------------------------------------------------------
MODULE 02 _ EX03 _ BSP
L'exercice demande d'indiqué si un point est dans un triangle.

A partir du dernier exercice, ajouter ceci

- Une nouvelle classe Point qui servira a memoriser des fixed point value x,y (canonique)
- Une fonction bsp qui prendra 4 points en parametre
	- 3 points d'un triangle
	- 1 point quelconque
	et qui retournera si le point quelconque est dans le triangle

Le main est laissé a notre discretion pour les tests.
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
make video_ref	-> Video pour fonction bsp
make triangle	-> Illustration du cas testé dans le main
make demo		-> make triangle + ./BSP
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
define TRIANGLE

------------------------------------------------------------------
                  Cas qui sont testés dans le main

  0 1 2 3 4 5 6 7 8 |
0                   |
                    |
1   a           2   |        Triangle:
    |\              |          a:  (1, 1)
2   | \             |          b:  (1, 7)
    |  \     5      |          c:  (7, 7)
3   |   3           |
    |    \          |        Point test:
4   |     \         |          p1: (3, 5)       inside  = true  (1)
    |      \        |          p2: (7, 1)       outside = false (0)
5   |   1   \       |          p3: (3, 3)       dessus  = false (0)
    |        6      |          p4: (1.5f, 6.5f) inside  = true  (1)
6   |         \     |          p5: (5.5f, 2.5f) outside = false (0)
    |4         \    |          p6: (5.5f, 5.5f) dessus  = false (0)
7   b___________c   |
                    |
8                   |

-------------------------------------------------------------------
endef
export TRIANGLE


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
			@$(RM) $(TEST_FILES)
			@echo "$RExecutable $(NAME) deleted$W"

triangle:
			@echo "$G$$TRIANGLE$W"

demo:
			@make triangle
			@./$(NAME)
			@echo "$C\nA votre tour de faire des tests en modifiant le main\n$W"

tools:
			@echo "$C$$TOOLS$W"

goal:
			@echo "$C$$EXPLANATION$W"

leak:
			$(LEAK_CMD) ./$(NAME)

pdf:
			@open https://cdn.intra.42.fr/pdf/pdf/66965/fr.subject.pdf

video_ref:
			@open https://youtu.be/kkucCUlyIUE

debug:	fclean
			@$(CC_DEBUG) $(CFLAGS) $(SRCS) -o $(NAME)_debug
			@echo "$YDebbuging executable ready!$W"

re:			fclean all

#PHONY--------------------------------------------------------------------------

.PHONY:				all clean fclean re init goal test art leak