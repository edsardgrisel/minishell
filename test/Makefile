NAME=minishell_test
CC=cc
CFLAGS=-g
SRCS=../src/minishell.c \
	$(wildcard ../src/execution/*.c) \
	$(wildcard ../src/helpers/*.c) \
	$(wildcard ../src/Parser/*.c)


TEST_SRCS= test_tokens.c test.c test_parsing.c test_builtins.c

HEADERS=-I ../lib/libft/include -I ../include -I include -I ../src/Parser -I ../src

OBJS = $(SRCS:.c=.o)
TEST_OBJS = $(TEST_SRCS:.c=.o)

LIBFT_DIR=../lib/libft
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