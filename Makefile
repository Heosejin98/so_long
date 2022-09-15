NAME		= so_long

CC 			= cc
FLAGS		= -Wall -Wextra -Werror


SRC_FILES	= main.c \
			io.c \
			ft_str.c \
			get_next_line.c \
			get_next_line_utils.c \
			map_init.c \
			map_check.c \
			mlx_init.c \
			move.c	\
			ft_itoa.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_strcmp.c \
			printf_walk.c 


MLX_DIR 	= mlx
MLX  		= mlx/Makefile
	
SRC_DIR		= ./src/
OBJ_DIR		= ./obj/
INCS		= -I ./include/
MLX_LIB		= -lmlx -framework OpenGl -framework AppKit -Imlx


GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
END_COLOR	= \033[0;39m

OBJ_FILES	= ${SRC_FILES:.c=.o}	
SRC			= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			= $(addprefix $(OBJ_DIR), $(OBJ_FILES))

all	: $(OBJ_DIR) $(NAME)

$(NAME) : $(OBJ)
	echo "$(GREEN)make $(PRI_DIR)"
	@$(CC) $(FLAGS) -o $@ $^ $(MLX_LIB)
	@echo "$(GREEN)$(NAME) compiled"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(FLAGS) -c $< -o $@  $(INCS)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean	:
		@rm -rf $(OBJ)
		@echo "$(YELLOW)$(NAME) clean"

fclean	:	clean
		@rm -rf $(NAME)
		@rm -rf $(OBJ_DIR)
		@echo "$(YELLOW)$(NAME) fclean"

re			:	fclean all

.PHONY		:	all clean fclean re bonus