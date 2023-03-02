
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

NAME 			= convertion
#CPP_LIST-----------------------------------------------------------------------
#  find ./*.cpp -type f | cut -c3- | sed 's/$/ \\/'

SRCS			=	main.cpp

#HPP_LIST-----------------------------------------------------------------------
#  find ./*.hpp -type f | cut -c3- | sed 's/$/ \\/'

HEADERS			=	 

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
MODULE 06 _ EX00 _ CONVERSION SCALAIRE

Écrire un programme qui prendra des char/int/float/double et qui les convertira
	dans les autres formats.
Il faut aussi prendre +inf, -inf, nan, +inff, -inff, nanf comme argument.
La conversion doit être fait avec des casts C++.
Si la conversion ne fonctionne pas, envoyer un message (impossible).

--------------------------------------------------------------------------------
endef
export EXPLANATION


#TOOLS--------------------------------------------------------------------------
define TOOLS
--------------------------------------------------------------------------------
OUTILS INCLUS DISPONIBLES
make goal		-> Vulgarisation du but de l'exercice
make test		-> Passe une série de tests
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

all: 	init $(NAME)

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
			clear
			@echo "$G\n-----ARG TESTS-----\n"
			@echo "$Z----TEST: $YNO ARG ----$W"
			./$(NAME)
			@echo "$Z\n----TEST: $YEMPTY ARG ----$W"
			./$(NAME) ""
			@echo "$Z\n----TEST: $YMULTIPLE ARG----$W"
			./$(NAME) 1 2
			@echo "$Z\n----TEST: $YMULTIPLE EMPTY ARG----$W"
			./$(NAME) "" ""
			@echo "$W\n press enter to continue\n"
			@read _
			clear
			@echo "$G\n-----INT TESTS-----"
			@echo "$Z\n----TEST :$YSIMPLE INT ----$W"
			./$(NAME) 42
			@echo "$Z\n----TEST :$YNEGATIVE INT ----$W"
			./$(NAME) -42
			@echo "$Z\n----TEST :$YPLUS SIGN INT ----$W"
			./$(NAME) +123
			@echo "$Z\n----TEST :$YOVERFLOW INT ----$W"
			./$(NAME) 123412341243432545
			@echo "$Z\n----TEST :$YOVERFLOW NEGATIVE INT ----$W"
			./$(NAME) -123412341243432545
			@echo "$W\n press enter to continue\n"
			@read _
			clear
			@echo "$G\n-----CHAR TESTS-----"
			@echo "$Z\n----TEST :$YSIMPLE CHAR ----$W"
			./$(NAME) "*"
			@echo "$Z\n----TEST :$YSPACE CHAR ----$W"
			./$(NAME) " "
			@echo "$Z\n----TEST :$YNUMBER CHAR (NOT CHAR) ----$W"
			./$(NAME) "0"
			@echo "$Z\n----TEST :$YNON PRINTABLE CHAR ----$W"
			./$(NAME) "127"
			@echo "$Z\n----TEST :$YSTRING ----$W"
			./$(NAME) aa
			@echo "$W\n press enter to continue\n"
			@read _
			clear
			@echo "$G\n-----FLOAT TESTS-----"
			@echo "$Z\n----TEST :$YSIMPLE FLOAT ----$W"
			./$(NAME) 3.4f
			@echo "$Z\n----TEST :$YNEGATIVE FLOAT ----$W"
			./$(NAME) -433.4f
			@echo "$Z\n----TEST :$YPLUS SIGN FLOAT ----$W"
			./$(NAME) +54.32f
			@echo "$Z\n----TEST :$YPRECISION FLOAT ----$W"
			./$(NAME) 1.12345678901234567901234567890123456789f
			@echo "$Z\n----TEST :$YBIG FLOAT ----$W"
			./$(NAME) 123456789012345678901234567890.123456789012345678901f
			@echo "$W\n press enter to continue\n"
			@read _
			clear
			@echo "$G\n-----DOUBLE TESTS-----"
			@echo "$Z\n----TEST :$YSIMPLE DOUBLE ----$W"
			./$(NAME) 3.4
			@echo "$Z\n----TEST :$YNEGATIVE DOUBLE ----$W"
			./$(NAME) -433.4
			@echo "$Z\n----TEST :$YPLUS SIGN DOUBLE ----$W"
			./$(NAME) +54.32
			@echo "$Z\n----TEST :$YPRECISION DOUBLE ----$W"
			./$(NAME) 1.12345678901234567901234567890123456789
			@echo "$Z\n----TEST :$YBIG DOUBLE ----$W"
			./$(NAME) 123456789012345678901234567890.123456789012345678901
			@echo "$W\n press enter to continue\n"
			@read _
			clear
			@echo "$G\n-----INF TESTS-----"
			@echo "$Z\n----TEST :$YONLY INF $R(NOT IN PDF)$Y ----$W"
			./$(NAME) inf
			@echo "$Z\n----TEST :$Y+INF ----$W"
			./$(NAME) +inf
			@echo "$Z\n----TEST :$Y-INF ----$W"
			./$(NAME) -inf
			@echo "$Z\n----TEST :$YONLY INFF $R(NOT IN PDF)$Y ----$W"
			./$(NAME) inff
			@echo "$Z\n----TEST :$Y+INFF ----$W"
			./$(NAME) +inff
			@echo "$Z\n----TEST :$Y-INFF ----$W"
			./$(NAME) -inff
			@echo "$W\n press enter to continue\n"
			@read _
			clear
			@echo "$G\n-----NAN TESTS-----"
			@echo "$Z\n----TEST :$YNAN ----$W"
			./$(NAME) nan
			@echo "$Z\n----TEST :$Y+NAN ----$W"
			./$(NAME) +nan
			@echo "$Z\n----TEST :$Y-NAN ----$W"
			./$(NAME) -nan
			@echo "$Z\n----TEST :$YNANF ----$W"
			./$(NAME) nanf
			@echo "$Z\n----TEST :$Y+NANF ----$W"
			./$(NAME) +nanf
			@echo "$Z\n----TEST :$Y-NANF ----$W"
			./$(NAME) -nanf
			@echo "$W\n press enter to continue\n"
			@read _
			clear
			@echo "$G\n-----OTHER TESTS-----"
			@echo "$Z\n----TEST :$YMULTIPLE - SIGN ----$W"
			./$(NAME) --3
			@echo "$Z\n----TEST :$YMULTIPLE + SIGN ----$W"
			./$(NAME) ++3
			@echo "$W\n press enter to continue\n"
			@read _
			clear
			@echo "$G\n-----LEAK TESTS-----"
			@echo "$Z\n----TEST :$YLEAK NORMAL ----$W"
			$(LEAK_CMD) ./$(NAME) 42f
			@echo "$Z\n----TEST :$YLEAK FAIL ----$W"
			$(LEAK_CMD) ./$(NAME) 42ff
			@echo "$G\n----END OF TEST----\n$W"

valgrind:
			$(VALGRIND_CMD) ./$(NAME)

pdf:
			@open https://cdn.intra.42.fr/pdf/pdf/58239/fr.subject.pdf

video42:
			@open https://elearning.intra.42.fr/tags/38/notions

debug:	fclean
			@$(CC_DEBUG) $(CFLAGS) $(SRCS) -o $(NAME)_debug
			@echo "$YDebbuging executable ready!$W"

re:			fclean all

#PHONY--------------------------------------------------------------------------

.PHONY:				all clean fclean re init goal test art leak debug tools