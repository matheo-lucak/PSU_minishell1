##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rtfm
##

MAIN				=	src/main.c

SRC					=	src/prompt.c				\
						src/builtin/builtin.c		\
						src/builtin/exit.c			\
						src/builtin/env.c			\
						src/builtin/setenv.c		\
						src/builtin/setenv_error.c	\
						src/builtin/unsetenv.c		\
						src/builtin/cd.c			\
						src/builtin/cd_back.c		\
						src/builtin/clean_path.c	\
						src/exec/exec.c				\
						src/exec/find_path.c		\

OBJ					=	$(SRC:.c=.o) $(MAIN:.c=.o)

NAME 				=	mysh

override CFLAGS		+=	-W -Wall -Wextra

override CPPFLAGS	+=	-I./include/

LDFLAGS				=	-L./lib/

override LDLIBS		+= 	-lmy

LIB 				= lib/libmy.a

all:				$(NAME)

$(NAME):			$(LIB) $(OBJ)
					$(LINK.o) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)

$(LIB):
					$(MAKE) -C lib/my

debug:				CPPFLAGS += -g
debug:				$(LIB)
					$(CC) -o $@ $(SRC) $(MAIN) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

tests_run:			LDLIBS += -lcriterion --coverage
tests_run:			CFLAGS += --coverage
tests_run:			$(LIB)
					$(CC) -o $@ $(SRC) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
					./$@
					mv *.gc* tests/
					$(RM) $@

clean:
					$(RM) $(OBJ)
					$(MAKE) -C lib/my clean

fclean:				clean
					$(RM) $(NAME)
					$(MAKE) -C lib/my fclean

re:			 		fclean all

.NOTPARALLEL:
.PHONY:				debug all clean fclean re tests_run
