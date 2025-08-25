NAME=libft.a
CC=cc
CFLAGS=-Wall -Wextra -Werror -g
PRINTF_DIR=ft_printf/src
PRINTF_SRCS=$(PRINTF_DIR)/ft_printf.c $(PRINTF_DIR)/print_char.c $(PRINTF_DIR)/print_hex.c \
	$(PRINTF_DIR)/print_numbers.c $(PRINTF_DIR)/print_pointer.c $(PRINTF_DIR)/print_str.c
SRCS= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
	ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
	ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	$(PRINTF_SRCS)
BONUSSRCS= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

.PHONY: all clean fclean re bonus

ifdef ISBONUS
OBJS=$(SRCS:.c=.o) $(BONUSSRCS:.c=.o)
else
OBJS=$(SRCS:.c=.o)
endif

all: $(NAME)


$(NAME): $(OBJS) $(FT_PRINTF_ARCHIVE)
	@ar -rcs $(NAME) $(OBJS)

bonus:
	@$(MAKE) ISBONUS=1 all

clean:
	@rm -f $(OBJS) $(BONUSSRCS:.c=.o)

fclean: clean
	@rm -f $(NAME)


re: fclean all
