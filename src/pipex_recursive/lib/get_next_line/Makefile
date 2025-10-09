NAME		:=  get_next_line.a
CFLAGS		:=  -Wextra -Wall -Werror
OBJ_DIR		:=	build
HEADERS		:= -I ./include
SRCS		:= 	\
				get_next_line_bonus.c \
				get_next_line_utils_bonus.c
OBJS		:=	$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
VPATH 		:= 	$(shell find src -type d)

all: $(NAME)
	
$(NAME): $(OBJS)
	@ar -rcs $(@) $(OBJS) && printf "Creating: $(notdir $@)\n\n"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p build
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

clean:
	@rm -rf $(OBJS)

fclean: clean
	@printf "Deleting $(NAME) - executables and build files\n"
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx