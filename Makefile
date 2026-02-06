NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX = minilibx-linux
LIBFT = libft

SRC = src/so_long.c \
		src/utils/ft_strcmp.c src/utils/error/handle_error.c \
		src/game/input.c src/game/render.c src/game/image.c src/game/close.c \
		src/map/map_check.c src/map/map_calc_size.c src/map/map_table.c \
		src/map/checks/check_path.c src/map/checks/check_wall.c src/map/checks/check_extension.c \
		src/map/checks/check_components.c src/map/checks/check_rect.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS = $(SRC:.c=.o)

MLX_FLAGS   = -L$(MLX) -lmlx -lXext -lX11 -lm -lz
LIBFT_FLAGS = -L$(LIBFT) -lft

INCLUDES = -I. -I$(MLX_PATH) -I$(LIBFT_PATH)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@make -C $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make -C $(LIBFT) clean
fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
