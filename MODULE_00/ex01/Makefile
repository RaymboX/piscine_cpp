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

NAME 			= 	palm_tungsten_e2

#CPP_LIST-----------------------------------------------------------------------
#  find ./*.cpp -type f | cut -c3- | sed 's/$/ \\/'

SRCS			= 	Contact.cpp \
					PhoneBook.cpp \
					main.cpp \

#HPP_LIST-----------------------------------------------------------------------
#  find ./*.hpp -type f | cut -c3- | sed 's/$/ \\/'

HEADERS			= 	Contact.hpp \
					PhoneBook.hpp 

#PROJECT EXPLANATION------------------------------------------------------------
define EXPLANATION
--------------------------------------------------------------------------------
MODULE 00 _ EX01 _ MY AWESOME_PHONEBOOK / MY_PALM_TUNGSTEN_E2

Faire un programme qui jouera le role d'un repertoire de contact
Pouvoir faire les commandes:
- ADD:    Ajout d'un contact
- SEARCH: Afficher les contacts par index / selectionner un index / affiche data
- EXIT:   Sortir du programme

Contact info: First/Last/Nick name, Phone number, Darkest secret

Ajout perso:
- Ajout d'un menu
- Parcing et formatage du numero de telephone
- Message d'erreur random

--------------------------------------------------------------------------------
endef
export EXPLANATION

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
			@echo "$G$(NAME) ready!$W"

init:
			@mkdir -p $(OBJS_DIR)

clean:
			@$(RM) $(OBJS)
			@$(RM) $(OBJS_DIR)
			@echo "$RObjects removed$W"

fclean: clean
			@$(RM) $(NAME)
			@$(RM) testfile log
			@echo "$RExecutable $(NAME) deleted$W"

goal:
			@echo "$C$$EXPLANATION$W"

test:
			@echo "$YTESTS BEGIN--------------------------------------$W"
			
			@echo "sdfsdf" > testfile
			@echo "SEARCH" >> testfile
			@echo "ADD" >> testfile
			@echo "Martin1111111111111" >> testfile
			@echo "Raymond111111111111" >> testfile
			@echo "RaymboX111111111111" >> testfile
			@echo "ddsf sdf sdf sdf" >> testfile
			@echo "4353456" >> testfile
			@echo "123-1231232" >> testfile
			@echo "1231231234" >> testfile
			@echo "Darkkkkkkkk11111111" >> testfile
			@echo "SEARCH" >> testfile
			@echo "" >> testfile
			@echo "0" >> testfile
			@echo "-1" >> testfile
			@echo "2" >> testfile
			@echo "1" >> testfile
			@echo "ADD" >> testfile
			@echo "Martin2" >> testfile
			@echo "Raymond2" >> testfile
			@echo "RaymboX2222222222222222222222" >> testfile
			@echo "1231231234" >> testfile
			@echo "Darkkkkkkkk2" >> testfile
			@echo "ADD" >> testfile
			@echo "Martin3" >> testfile
			@echo "Raymond3" >> testfile
			@echo "RaymboX3" >> testfile
			@echo "1231231234" >> testfile
			@echo "Darkkkkkkkk3" >> testfile
			@echo "ADD" >> testfile
			@echo "Martin4" >> testfile
			@echo "Raymond4" >> testfile
			@echo "RaymboX4" >> testfile
			@echo "1231231234" >> testfile
			@echo "Darkkkkkkkk4" >> testfile
			@echo "ADD" >> testfile
			@echo "Martin5" >> testfile
			@echo "Raymond5" >> testfile
			@echo "RaymboX5" >> testfile
			@echo "1231231234" >> testfile
			@echo "Darkkkkkkkk5" >> testfile
			@echo "ADD" >> testfile
			@echo "Martin6" >> testfile
			@echo "Raymond6" >> testfile
			@echo "RaymboX6" >> testfile
			@echo "1231231234" >> testfile
			@echo "Darkkkkkkkk6" >> testfile
			@echo "ADD" >> testfile
			@echo "Martin7" >> testfile
			@echo "Raymond7" >> testfile
			@echo "RaymboX7" >> testfile
			@echo "1231231234" >> testfile
			@echo "Darkkkkkkkk7" >> testfile
			@echo "ADD" >> testfile
			@echo "Martin8" >> testfile
			@echo "Raymond8" >> testfile
			@echo "RaymboX8" >> testfile
			@echo "1231231234" >> testfile
			@echo "Darkkkkkkkk8" >> testfile
			@echo "ADD" >> testfile
			@echo "Martin999999999999999" >> testfile
			@echo "Raymond9" >> testfile
			@echo "RaymboX9" >> testfile
			@echo "1231231234" >> testfile
			@echo "Darkkkkkkkk9999" >> testfile
			@echo "SEARCH" >> testfile
			@echo "2" >> testfile
			@echo "EXIT" >> testfile
			$(LEAK_CMD) ./$(NAME) < testfile > log
			@echo "$Y\nEND OF TESTS----------------------------------$W"
re:			fclean all

palm:
			@open https://en.wikipedia.org/wiki/Palm_Tungsten

#PHONY--------------------------------------------------------------------------

.PHONY:				all clean fclean re init goal test