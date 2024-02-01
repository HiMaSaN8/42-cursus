NAME = push_swap

SRCS = push_swap.c \

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -Ilibft -Ift_printf

RM = rm -f

all: $(NAME)

$(NAME): libft/libft.a ft_printf/libftprintf.a $(OBJS)
		$(CC) $(OBJS) $(CFLAGS) libft/libft.a ft_printf/libftprintf.a -o $(NAME)



libft/libft.a:
			make -C libft

ft_printf/libftprintf.a:
			make -C ft_printf
		
%.o : %.c libft/libft.h ft_printf/libftprintf.h
		$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJS)
	make -C libft clean
	make -C ft_printf clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean
	make -C ft_printf fclean
re: fclean all

.PHONY: all clean fclean re