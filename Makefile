CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
SRC = main.c ft_split.c ft_strchr.c ft_strjoin.c ft_strlen.c ft_strncmp.c helper.c pipex.c pipex_utils.c ft_putstr_fd.c ft_putchar_fd.c 
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ)  -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
