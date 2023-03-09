NAME			=	mod01
CFLAGS 			= 	-Wall -Werror -Wextra -std=c++98
MAIN_FILE		=	main01.cpp
SRCS			=	$(MAIN_FILE) \
					Warlock.cpp \
					ASpell.cpp \
					ATarget.cpp \
					Fwoosh.cpp \
					Dummy.cpp

define MAIN_CONTENT
#include "Warlock.hpp"
#include "ATarget.hpp"
#include "ASpell.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"

int main()
{
  Warlock richard("Richard", "the Titled");

  Dummy bob;
  Fwoosh* fwoosh = new Fwoosh();

  richard.learnSpell(fwoosh);

  richard.introduce();
  richard.launchSpell("Fwoosh", bob);

  richard.forgetSpell("Fwoosh");
  richard.launchSpell("Fwoosh", bob);
}
endef
export MAIN_CONTENT

all:
	@echo "$$MAIN_CONTENT" > $(MAIN_FILE)
	g++ $(CFLAGS) $(SRCS) -o $(NAME)

fclean:
	rm -rf $(NAME) $(MAIN_FILE)