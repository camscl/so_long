NAME		=	so_long

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror

SRCS = src/main.c \
	src/input.c src/s_tates.c src/pr_shell.c \
	src/map.c src/map_utils.c src/map_utils_plus.c src/map_possition.c \
	src/render_init.c 
SRCS_MANDATORY = src/draw.c 
OBJS = $(SRCS:.c=.o)
OBJS_MANDATORY = $(SRCS_MANDATORY:.c=.o)

INCLUDE = so_long.h

LIBFT = libft
LIBFT_FLAGS = -L libs/libft -lft

SRCS_GNL = libs/get_next_line/get_next_line_utils.c \
		   libs/get_next_line/get_next_line.c

OBJS_GNL = $(SRCS_GNL:.c=.o)
GNL = get_next_line

MLX = mlx
MLX_FLAGS = -L libs/mlx -lmlx

INC_FLAGS = -I includes/so_long \
	-I includes -I libs/$(LIBFT) -I libs/$(GNL) -I libs/$(MLX) 

NORM = norminette


all:  $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	@make bonus --silent --directory=libs/$(LIBFT)


$(MLX):
	@make --silent --directory=libs/$(MLX)


$(NAME): $(OBJS) $(OBJS_GNL) $(OBJS_MANDATORY) 

	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_FLAGS) $(MLX_FLAGS)
	install_name_tool -change libmlx.dylib $(CURDIR)/libs/mlx/libmlx.dylib so_long

%.o: %.c

	$(CC) $(CFLAGS) -c $< -o $@ $(INC_FLAGS)

bonus: $(OBJS) $(OBJS_GNL) $(OBJS_BONUS)

	$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBFT_FLAGS) $(MLX_FLAGS)
	install_name_tool -change libmlx.dylib $(CURDIR)/libs/mlx/libmlx.dylib so_long

clean:
	@make clean --directory=libs/$(LIBFT)
	@make clean --directory=libs/$(MLX)
	rm -f $(OBJS) $(OBJS_GNL) $(OBJS_MANDATORY) $(OBJS_BONUS)

fclean: clean
	make fclean --directory=libs/$(LIBFT)

	rm -f $(NAME)
	rm -rf $(NAME).dSYM
	@echo "binary file removed."
norme:
	@$(NORM) $(SRCS) $(SRCS_MANDATORY) $(INCLUDE)

re:			fclean all

.PHONY:		all clean fclean re