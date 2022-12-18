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

NAME 			= hordezzz

#CPP_LIST-----------------------------------------------------------------------
#  find ./*.cpp -type f | cut -c3- | sed 's/$/ \\/'

SRCS			=	main.cpp \
					zombieHorde.cpp \
					Zombie.cpp 

#HPP_LIST-----------------------------------------------------------------------
#  find ./*.hpp -type f | cut -c3- | sed 's/$/ \\/'

HEADERS			= Zombie.hpp

#PROJECT EXPLANATION------------------------------------------------------------
define EXPLANATION
--------------------------------------------------------------------------------
MODULE 01 _ EX01 _ ENCORE PLUS DE CERVEAUX!
Implementer avec la classe Zombie,
 la fonction Zombie	*zombieHorde(int N, std::string name);

Cette fonction demande a initialiser un array d'instance de classe.
--------------------------------------------------------------------------------
endef
export EXPLANATION

define ART
                  .....                  .....                  ..... 
                 C C  /                 C C  /                 C C  / 
                /<   /                 /<   /                 /<   /  
 ___ __________/_#__=o  ___ __________/_#__=o  ___ __________/_#__=o  
/(- /(\_\________   \  /(- /(\_\________   \  /(- /(\_\________   \  
\ ) \ )_      \o     \ \ ) \ )_      \o     \ \ ) \ )_      \o     \ 
/|\ /|\       |'     | /|\ /|\       |'     | /|\ /|\       |'     | 
              |     _|               |     _|               |     _|   
              /o   __\               /o   __\               /o   __\   
             / '     |              / '     |              / '     |   
            / /      |             / /      |             / /      |   
           /_/\______|            /_/\______|            /_/\______|   
          (   _(    <            (   _(    <            (   _(    <    
           \    \    \            \    \    \            \    \    \   
            \    \    |            \    \    |            \    \    |  
             \____\____\            \____\____\            \____\____\ 
             ____\_\__\_\           ____\_\__\_\           ____\_\__\_\ 
           /`   /`     o\         /`   /`     o\         /`   /`     o\ 
           |___ |_______|         |___ |_______|         |___ |_______| 
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