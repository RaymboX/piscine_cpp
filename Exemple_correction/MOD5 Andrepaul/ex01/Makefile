###---------------------------------MAKEFILE------------------------------###
###-----------------------------------------------------------------------###
###              #       #######     				     /\               ###
###             ###      ##    ##  				       _(  )_             ###
###            ## ##     ##    ## 					 (`_\\//_`)           ###
###           #######    #######     				  `={==}=`            ###
###          ###   ###   ##        					  .->/\<-.            ###
###         ###     ###  ##           				   "`\/`"             ###
###-----------------------------------------------------------------------###
###Made by André-Paul Grenon--#useraddress: agrenon@student.42quebec.com--###
#-------------------------------------------------------------------------###
###THIS PROJECT: SO_LONG 
NAME = ex01 #(Nom de L'exécutable)

###----------------####1.  VARIABLES####----------------------------------###

BONUS = 

### Fichiers .c
SRCS_C	= main.cpp Bureaucrat.cpp Form.cpp

INCLUDE	= Bureaucrat.hpp Form.hpp colours.hpp

#Crée les fichiers objets à partir des fichiers .c:
OBJS_O			= $(SRCS_C:.cpp=.o)

#VPATH			= $(DIR) $(B_DIR)
###Préfixes:
DIR			=
OBJS_DIR	=
INCLUDE 	=	

### Répertoires:
SRCS		= $(SRCS_C)
OBJS		= $(OBJS_O)


### Compilation, archivage et autres fonctions
CC			= c++
CFLAGS		= -Wall -Werror -Wextra -O3
CCOMP		= -std=c++98 
OEXEC		= -o $(NAME)

RM			= rm -rf
NORM		= norminette

### Couleurs et fonctionnalités texte:

END         = \033[0m
BOLD        = \033[1m
ITALIC      = \033[3m
URL         = \033[4m
BLINK       = \033[5m
BLINK2      = \033[6m
SELECTED    = \033[7m

BLACK       = \033[30m
RED         = \033[31m
GREEN       = \033[32m
YELLOW      = \033[33m
BLUE        = \033[34m
VIOLET      = \033[35m
BEIGE       = \033[36m
WHITE       = \033[37m

###-----------------###-2. REGLES ##-------------------------------------###

all:	$(NAME)

(OBJS)%.o:%.cpp
	$(CC) $(CFLAGS) -o $@ -cpp $<

$(NAME): 	$(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) $(OEXEC) $(CCOMP)
			@echo "\n$(BOLD)$(GREEN)Compilation de l'exécutable $(NAME) effectuée avec succès!\n" 
		@echo "$(BLUE)$(BOLD)             8" && echo "           .d8b." && echo "       _.d8888888b._" && echo "     .88888888888888b." && echo "    d88888888888888888b" && echo "    8888888888888888888" && echo "    Y88888888888888888P" && echo "     'Y8888888888888P'" && echo "   _..._ 'Y88888P' _..._" && echo " .d88888b. Y888P .d88888b." && echo "d888888888b 888 d88888888b" && echo "888P  'Y8888888888P'  Y888" && echo " b8b    Y88888888P    d8Y" && echo "   \   #############  /" && echo "         dP d8b Yb" && echo "     Ob=dP d888b Yb=dO" && echo "       ¨  O88888O  ¨" && echo "           'Y8P'" &&echo "             '$(END) $(VIOLET)"

clean:
		$(RM) $(OBJS_O)
		@echo "\n $(RED)$(ITALIC)Les fichiers .o sont correctement supprimés\n $(END)"

fclean: clean 
		$(RM) ${NAME}
		@echo "$(BOLD)$(RED)\nATTENTION! Purge effectuée.\n$(END)"

re : 	fclean 
		@make
