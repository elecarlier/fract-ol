# Program name
NAME		= fractol

# Compiler
CC			= cc
CFLAGS		= -Werror -Wextra -Wall

# Minilibx
MLX_PATH	= minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

# Libft
LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# Includes
INC			= -I ./includes/ -I ./libft/ -I ./minilibx-linux/

# Sources
SRC			=	main.c fractal_init.c math_utils.c render.c param.c

# Objects
OBJ			= $(SRC:.c=.o)

all: $(MLX) $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling fractol..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) $(LIBFT) $(INC) -lXext -lX11 -lm
	@echo "Fractol ready."

%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(MLX):
	@echo "Making MiniLibX..."
	@make -sC $(MLX_PATH)

$(LIBFT):
	@echo "Making libft..."
	@make -sC $(LIBFT_PATH)

clean:
	@echo "Removing object files..."
	@rm -f $(OBJ)

fclean: clean
	@echo "Removing fractol..."
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: all re clean fclean
