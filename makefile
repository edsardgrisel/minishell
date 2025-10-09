#----------------------------VARIABLES-------------------------#

#COMPILE VARIABLES
CC			:=	cc
CFLAGS		:=	-Wextra -Wall -Werror -g

##LIBRARIES (MANDATORY AND BONUS)
LIBFT		:=	./lib/libft
PIPEX		:= 	./lib/pipex
#PROJECT MANDATORY
NAME		:=	minishell
HEADERS		:=	-I ./include \
				-I $(LIBFT)/include \
				-I $(PIPEX)/include
LIBS		:=	$(PIPEX)/pipex.a \
				$(LIBFT)/libft.a 
OBJ_DIR		:=	build
SRCS		:= 	main_minishell.c \
				minishell.c \
				ft_strndup.c \
				ft_strjoin_char.c \
				ft_str_list_join.c \
				parser.c \
				tokenizer.c \
				parse_command.c \
				parsing_cleanup.c \
				echo.c \
				execution.c \
				pwd.c \
				env.c \
				exit.c \
				cd.c \
				env_helpers.c \
				export.c
OBJS		:=	$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
VPATH 		:=	$(shell find src -type d)

#----------------------------RULES-------------------------#
all: LIBFT $(NAME)
bonus: LIBFT $(NAME_BNS)


#LIBRARIES RULES
LIBFT:
	@make -C $(LIBFT) --no-print-directory -s

#COMPILING BUILD FILES
$(OBJ_DIR)/%.o: %.c | build
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"


#CREATING EXECUTABLE
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -lreadline -o $(NAME) && printf "Binary made: $(notdir $@)\n\n"


#Create build directory if it doesn't exist
build:
	mkdir -p build

#CLEANING
clean:
	@printf "Deleting $(NAME) - executables and build files\n"
	@rm -rf $(OBJS) $(OBJS_BNS)
fclean: clean
	@make -C $(LIBFT) fclean --no-print-directory
	@rm -rf $(NAME) $(NAME_BNS)
re: clean all

.PHONY: all, bonus, clean, LIBFT, fclean, re