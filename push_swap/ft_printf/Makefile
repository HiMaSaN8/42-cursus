NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = 			ft_printf.c ib_print.c ib_print2.c
				
OBJS = $(SRC:.c=.o)

all: ${NAME}
${NAME}:	${OBJS}
	ar -rcs ${NAME} ${OBJS}
clean: 
			rm -f ${OBJS}
fclean:
			rm -f ${OBJS} ${NAME}
re:	fclean all 

.PHONY : 	all clean fclean re