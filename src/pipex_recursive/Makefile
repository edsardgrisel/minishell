#----------------------------VARIABLES-------------------------#

#COMPILE VARIABLES
CC			:=	cc
CFLAGS		:=	-Wextra -Wall #-Werror

##LIBRARIES (MANDATORY AND BONUS)
LIBFT		:=	./lib/libft
LIBGTNXTLNE :=	./lib/get_next_line


#PROJECT MANDATORY
NAME		:=	pipex
HEADERS		:=	-I ./include \
				-I $(LIBFT)/include \
				-I $(LIBGTNXTLNE)/include
LIBS		:=	$(LIBFT)/libft.a
OBJ_DIR		:=	build
SRCS		:= 	main.c \
				helpers.c \
				execute_program.c \
				child_process.c \
				set_stdin.c \
				set_stdout.c
OBJS		:=	$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
VPATH 		:=	src src_bonus

#PROJECT BONUS
NAME_BNS	:=	pipex_bonus
HEADERS_BNS	:=	-I ./include \
				-I $(LIBFT)/include \
				-I $(LIBGTNXTLNE)/include
LIBS_BNS	:= 	$(LIBFT)/libft.a \
				$(LIBGTNXTLNE)/get_next_line.a
SRCS_BNS	:= 	heredoc_bonus.c \
				main_bonus.c
OBJS_BNS	:=	$(filter-out build/main.o, $(OBJS)) $(addprefix $(OBJ_DIR)/,$(SRCS_BNS:.c=.o))


#----------------------------RULES-------------------------#
all: LIBFT $(NAME)
bonus: LIBFT LIBGTNXTLNE $(NAME_BNS)


#LIBRARIES RULES
LIBFT:
	@make -C $(LIBFT) --no-print-directory -s
LIBGTNXTLNE:
	@make -C $(LIBGTNXTLNE) --no-print-directory -s


#COMPILING BUILD FILES
$(OBJ_DIR)/%.o: %.c | build
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"


#CREATING EXECUTABLE
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) && printf "Binary made: $(notdir $@)\n\n"
$(NAME_BNS): $(OBJS_BNS)
	@$(CC) $(OBJS_BNS) $(LIBS_BNS) $(HEADERS_BNS) -o $(NAME_BNS) && printf "Binary made: $(notdir $@)\n\n"

#Create build directory if it doesn't exist
build:
	mkdir -p build

#CLEANING
clean:
	@printf "Deleting $(NAME) - executables and build files\n"
	@rm -rf $(OBJS) $(OBJS_BNS)
fclean: clean
	@make -C $(LIBFT) fclean --no-print-directory
	@make -C $(LIBGTNXTLNE) fclean --no-print-directory
	@rm -rf $(NAME) $(NAME_BNS)
re: clean all

.PHONY: all, bonus, clean, LIBFT, LIBGTNXTLNE, fclean, re