NAME=minishell_test
CC=cc
CFLAGS=-g
SRCS= ../ft_strndup.c \
    ../minishell.c \
    ../parsing/parser.c \
    ../parsing/tokenizer.c \
	../parsing/parse_command.c \
	../ft_strjoin_char.c \
	../parsing/parsing_cleanup.c

TEST_SRCS= test_tokens.c test.c test_parsing.c

HEADERS=-I ../libft -I ../include -I include -I ../parsing 

OBJS = $(SRCS:.c=.o)
TEST_OBJS = $(TEST_SRCS:.c=.o)

LIBFT_DIR=../libft
LIBFT_ARCHIVE=$(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(TEST_OBJS) $(LIBFT_ARCHIVE)
	$(CC) $(CFLAGS) $(OBJS) $(TEST_OBJS) $(LIBFT_ARCHIVE) -lreadline -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(LIBFT_ARCHIVE):
	$(MAKE) -s -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJS) $(TEST_OBJS)
	$(MAKE) -s -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	$(MAKE) -s -C $(LIBFT_DIR) fclean

re: fclean all