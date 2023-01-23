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

#TESTFILE-----------------------------------------------------------------------
TESTFILE		= testfile

LOGFILE			= test.log

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

#TOOLS--------------------------------------------------------------------------
define TOOLS
--------------------------------------------------------------------------------
OUTILS INCLUS DISPONIBLES
make goal		-> Vulgarisation du but de l'exercice
make pdf 		-> Ouvre le PDF sujet
make test		-> Lance une série de tests exporter dans un fichier test.log
make tools		-> Affiche les outils disponibles (ceci)
make palm		-> Ouvre une page avec la description du palm tungsten e2
--------------------------------------------------------------------------------
endef
export TOOLS

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
			@make tools

init:
			@mkdir -p $(OBJS_DIR)

clean:
			@$(RM) $(OBJS)
			@$(RM) $(OBJS_DIR)
			@echo "$RObjects removed$W"

fclean: clean
			@$(RM) $(NAME)
			@$(RM) $(TESTFILE) $(LOGFILE)
			@echo "$RExecutable $(NAME) deleted$W"

goal:
			@echo "$C$$EXPLANATION$W"

tools:
			@echo "$C$$TOOLS$W"

pdf:
			@open https://cdn.intra.42.fr/pdf/pdf/59641/fr.subject.pdf

test:
			@echo "$YTESTS BEGIN--------------------------------------$W"
			
#$(TESTFILE) creation#########################################
			@echo "sdfsdf" > $(TESTFILE)
			@echo "SEARCH" >> $(TESTFILE)
			@echo "ADD" >> $(TESTFILE)
			@echo "Martin1111111111111" >> $(TESTFILE)
			@echo "Raymond111111111111" >> $(TESTFILE)
			@echo "RaymboX111111111111" >> $(TESTFILE)
			@echo "ddsf sdf sdf sdf" >> $(TESTFILE)
			@echo "4353456" >> $(TESTFILE)
			@echo "123-1231232" >> $(TESTFILE)
			@echo "1231231234" >> $(TESTFILE)
			@echo "Darkkkkkkkk11111111" >> $(TESTFILE)
			@echo "SEARCH" >> $(TESTFILE)
			@echo "" >> $(TESTFILE)
			@echo "0" >> $(TESTFILE)
			@echo "-1" >> $(TESTFILE)
			@echo "2" >> $(TESTFILE)
			@echo "1" >> $(TESTFILE)
			@echo "ADD" >> $(TESTFILE)
			@echo "Martin2" >> $(TESTFILE)
			@echo "Raymond2" >> $(TESTFILE)
			@echo "RaymboX2222222222222222222222" >> $(TESTFILE)
			@echo "1231231234" >> $(TESTFILE)
			@echo "Darkkkkkkkk2" >> $(TESTFILE)
			@echo "ADD" >> $(TESTFILE)
			@echo "Martin3" >> $(TESTFILE)
			@echo "Raymond3" >> $(TESTFILE)
			@echo "RaymboX3" >> $(TESTFILE)
			@echo "1231231234" >> $(TESTFILE)
			@echo "Darkkkkkkkk3" >> $(TESTFILE)
			@echo "ADD" >> $(TESTFILE)
			@echo "Martin4" >> $(TESTFILE)
			@echo "Raymond4" >> $(TESTFILE)
			@echo "RaymboX4" >> $(TESTFILE)
			@echo "1231231234" >> $(TESTFILE)
			@echo "Darkkkkkkkk4" >> $(TESTFILE)
			@echo "ADD" >> $(TESTFILE)
			@echo "Martin5" >> $(TESTFILE)
			@echo "Raymond5" >> $(TESTFILE)
			@echo "RaymboX5" >> $(TESTFILE)
			@echo "1231231234" >> $(TESTFILE)
			@echo "Darkkkkkkkk5" >> $(TESTFILE)
			@echo "ADD" >> $(TESTFILE)
			@echo "Martin6" >> $(TESTFILE)
			@echo "Raymond6" >> $(TESTFILE)
			@echo "RaymboX6" >> $(TESTFILE)
			@echo "1231231234" >> $(TESTFILE)
			@echo "Darkkkkkkkk6" >> $(TESTFILE)
			@echo "ADD" >> $(TESTFILE)
			@echo "Martin7" >> $(TESTFILE)
			@echo "Raymond7" >> $(TESTFILE)
			@echo "RaymboX7" >> $(TESTFILE)
			@echo "1231231234" >> $(TESTFILE)
			@echo "Darkkkkkkkk7" >> $(TESTFILE)
			@echo "ADD" >> $(TESTFILE)
			@echo "Martin8" >> $(TESTFILE)
			@echo "Raymond8" >> $(TESTFILE)
			@echo "RaymboX8" >> $(TESTFILE)
			@echo "1231231234" >> $(TESTFILE)
			@echo "Darkkkkkkkk8" >> $(TESTFILE)
			@echo "ADD" >> $(TESTFILE)
			@echo "Martin999999999999999" >> $(TESTFILE)
			@echo "Raymond9" >> $(TESTFILE)
			@echo "RaymboX9" >> $(TESTFILE)
			@echo "1231231234" >> $(TESTFILE)
			@echo "Darkkkkkkkk9999" >> $(TESTFILE)
			@echo "SEARCH" >> $(TESTFILE)
			@echo "2" >> $(TESTFILE)
			@echo "EXIT" >> $(TESTFILE)
#$(TESTFILE) created##########################################

			$(LEAK_CMD) ./$(NAME) < $(TESTFILE) > $(LOGFILE)
			@echo "$Y\nEND OF TESTS----------------------------------$W"
re:			fclean all

palm:
			@open https://en.wikipedia.org/wiki/Palm_Tungsten

#PHONY--------------------------------------------------------------------------

.PHONY:				all clean fclean re init goal test