R = $(shell tput -Txterm setaf 1)
G = $(shell tput -Txterm setaf 2)
W = $(shell tput -Txterm setaf 7)
C = $(shell tput -Txterm setaf 6)
Y = $(shell tput -Txterm setaf 3)
Z = $(shell tput -Txterm setaf 5)

all: fclean
		git add .
		git status
		@echo "--------------Last commits (newest to oldest)-------------"
		@echo "$G"
		@git log -n 3 --pretty="format:%ci  -  %cr  -  %s"
		@echo "$W"
		@echo "----------------------------------------------------------"
		@echo "\n TIME TO : git commit -m \n"

push:
		@git push
		@echo "\n------Last commit confirmation-------"
		@echo "$G"
		@git log -n 1 --pretty="format:%cr -> %s"
		@echo "$W"

video42:
			@open https://elearning.intra.42.fr/tags/38/notions

fclean:
		$(MAKE) -s fclean -C MOD00/ex00
		$(MAKE) -s fclean -C MOD00/ex01
		$(MAKE) -s fclean -C MOD00/ex02
		$(MAKE) -s fclean -C MOD01/ex00
		$(MAKE) -s fclean -C MOD01/ex01
		$(MAKE) -s fclean -C MOD01/ex02
		$(MAKE) -s fclean -C MOD01/ex03
		$(MAKE) -s fclean -C MOD01/ex04
		$(MAKE) -s fclean -C MOD01/ex05
		$(MAKE) -s fclean -C MOD01/ex06
		$(MAKE) -s fclean -C MOD02/ex00
		$(MAKE) -s fclean -C MOD02/ex01
		$(MAKE) -s fclean -C MOD02/ex02
		$(MAKE) -s fclean -C MOD02/ex03
		$(MAKE) -s fclean -C MOD03/ex00
		$(MAKE) -s fclean -C MOD03/ex01
		$(MAKE) -s fclean -C MOD03/ex02
		$(MAKE) -s fclean -C MOD03/ex03
		$(MAKE) -s fclean -C MOD04/ex00
		$(MAKE) -s fclean -C MOD04/ex01
		$(MAKE) -s fclean -C MOD04/ex02
		$(MAKE) -s fclean -C MOD05/ex00
		$(MAKE) -s fclean -C MOD05/ex01
		$(MAKE) -s fclean -C MOD05/ex02
		$(MAKE) -s fclean -C MOD05/ex03
		$(MAKE) -s fclean -C MOD06/ex00
		$(MAKE) -s fclean -C MOD06/ex01
		$(MAKE) -s fclean -C MOD06/ex02
		$(MAKE) -s fclean -C MOD07/ex00
		$(MAKE) -s fclean -C MOD07/ex01
		$(MAKE) -s fclean -C MOD07/ex02
		$(MAKE) -s fclean -C MOD08/ex00
