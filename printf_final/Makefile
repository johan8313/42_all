NAME		= libftprintf.a

CC			= gcc
RM			= rm -rf
AR			= ar rcs
CFLAGS		= -Wall -Wextra -Werror

SRC			= ft_print_hex ft_print_ptr ft_print_unsigned ft_printf_utils ft_printf
SRCS		= $(addsuffix .c, ${SRC})

OBJ_DIR		= obj
OBJS		= ${SRCS:%.c=$(OBJ_DIR)/%.o}

LIBFT_PATH	= ./libft
LIBFT		= $(LIBFT_PATH)/libft.a

$(OBJ_DIR)/%.o:		%.c
						${CC} ${CFLAGS} -c $< -o $@

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJ_DIR) $(OBJS)
				cp	$(LIBFT) $(NAME)
					$(AR) $(NAME) $(OBJS)

$(LIBFT):
					make -C $(LIBFT_PATH) all

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
			make -C $(LIBFT_PATH) clean
			${RM} ${OBJ_DIR}

fclean:		clean
			make -C $(LIBFT_PATH) fclean
			${RM} $(NAME)

re:			fclean all

.PHONY:		all clean fclean re libft
