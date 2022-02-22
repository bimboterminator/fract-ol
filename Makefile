SRC = main.c put_pixel.c clear.c init.c color.c draw.c events.c \
mandelbrot.c julia.c 
SRC_DIR = src
OBJ_DIR = objs
SRCS = $(addprefix $(SRC_DIR)/,$(SRC))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
NAME = fractol
INCLUDE_DIR = include
HEADERS = $(addprefix $(INCLUDE_DIR)/, fractol.h)
LIB_OPT = -L/usr/local/lib -lmlx_Linux -lXext -lX11 -lm -lz -L./libft -lft
LIBFT_DIR = libft
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(OBJS): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	cc -I$(INCLUDE_DIR) -o $@ -c $<

$(NAME): LIB $(OBJS) 
	cc $(OBJS) $(LIB_OPT) -o $(NAME)

LIB:
	@make -C $(LIBFT_DIR)
clean:
	rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	
re: fclean all

.PHONY: clean fclean re