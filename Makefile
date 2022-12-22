

all: fclean
		git add .
		git status

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

