SRC = main.c put_pixel.c clear.c init.c color.c draw.c events.c \
mandelbrot.c julia.c transform.c
SRC_DIR = src/
OBJ_DIR = objs/
SRCS = $(addprefix $(SRC_DIR),$(SRC))
OBJS = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
NAME = fractol
INCLUDE_DIR = include
HEADERS = $(addprefix $(INCLUDE_DIR)/, fractol.h keys.h)
LIB_OPT = -Lmlx -lmlx -framework OpenGL -framework AppKit -L./libft -lft -lm
LIBFT_DIR = ./libft
MLX_DIR = ./mlx
LIBFT = libft
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	cc $(CFLAGS) -I$(INCLUDE_DIR) -Ilibft -Imlx -o $@ -c $<

object_dir: 
	@mkdir -p $(OBJ_DIR)

$(NAME): libmlx lib object_dir $(OBJS) 
	cc $(CFLAGS) $(OBJS) $(LIB_OPT) -o $(NAME)

lib:
	@make -sC $(LIBFT_DIR)

libmlx:
	@make -sC $(MLX_DIR)

clean:
	rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_DIR)/libft.a

re: fclean all

.PHONY: clean fclean re