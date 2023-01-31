

all: fclean
		git add .
		git status
		@echo "--------------Last commits (oldest to newest)-------------"
		@git log --reverse -n 3 --pretty="format:%ci  -  %cr  -  %s"
		@echo "----------------------------------------------------------"
		@echo "\n TIME TO : git commit -m \n"

push:
		@git push
		@echo "\n------Last commit confirmation-------"
		@git log -n 1 --pretty="format:%cr -> %s"


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
