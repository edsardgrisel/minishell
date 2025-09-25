NAME=minishell_test
CC=cc
CFLAGS=-g
SRCS=../minishell.c \
	../ft_strndup.c \
	../ft_strjoin_char.c \
	../parsing/parser.c \
	../parsing/tokenizer.c \
	../parsing/parse_command.c \
	../parsing/parsing_cleanup.c \
	../execution/echo.c \
	../execution/execution.c \
	../execution/pwd.c \
	../execution/env.c \
	../execution/exit.c \
	../execution/cd.c \
	../execution/env_helpers.c \
	../execution/export.c \
	../parsing/arg_list.c


TEST_SRCS= test_tokens.c test.c test_parsing.c test_builtins.c

HEADERS=-I ../libft -I ../include -I include -I ../parsing -I ../

OBJS = $(SRCS:.c=.o)
TEST_OBJS = $(TEST_SRCS:.c=.o)

LIBFT_DIR=../libft
LIBFT_ARCHIVE=$(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re libft

all: libft $(NAME)

$(NAME): $(TEST_OBJS) Makefile $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(TEST_OBJS) $(LIBFT_ARCHIVE) -lreadline -o $(NAME)

%.o: %.c Makefile
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

libft:
	@$(MAKE) -s -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJS) $(TEST_OBJS)
	$(MAKE) -s -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	$(MAKE) -s -C $(LIBFT_DIR) fclean

re: fclean all