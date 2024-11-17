NAME		= push_swap

CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -g3

SRC			= main checker utils sorting_algo swap push rotate reverse_rotate
SRCS		= $(addsuffix .c, ${SRC})

OBJ_DIR		= obj
OBJS		= ${SRCS:%.c=$(OBJ_DIR)/%.o}

MLX_PATH	= ./minilibx-linux
MLX_LIB		= $(MLX_PATH)/libmlx.a

LIBFT_PATH	= ./libft
LIBFT		= $(LIBFT_PATH)/libft.a

$(OBJ_DIR)/%.o:		%.c
	@${CC} ${CFLAGS} -c $< -o $@

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJ_DIR) $(OBJS)
	@cp	$(LIBFT) $(NAME)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH) all

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
	@make -C $(LIBFT_PATH) clean
	${RM} ${OBJ_DIR}

fclean:		clean
	@make -C $(LIBFT_PATH) fclean
	${RM} $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
