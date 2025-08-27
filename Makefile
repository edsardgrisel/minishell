NAME=minishell
CC=cc
CFLAGS=-Wall -Wextra -Werror -g
SRCS= cleaup.c \
	main.c \
	minishell.c \
	parser.c \
	ft_strndup.c \
	tokenizer.c \

HEADERS=-I ./libft

LIBFT_DIR=./libft
LIBFT_ARCHIVE=$(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_ARCHIVE)
	$(CC) $(OBJS) $(LIBFT_ARCHIVE) -o $(NAME)

$(LIBFT_ARCHIVE):
	$(MAKE) -s -C $(LIBFT_DIR) bonus

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
