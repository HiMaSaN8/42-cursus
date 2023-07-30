CFLAGS = -Wall -Wextra -Werror

SRC = ft_isalpha.c ft_bzero.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_tolower.c ft_toupper.c ft_strncmp.c ft_strrchr.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c
OBJ = $(SRC:.c=.o)
CC = gcc
RM = rm -f
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)

	ar -rcs $(NAME) $(OBJ)


