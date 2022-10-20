CC = gcc

PATH_MLX = ./minilibx-linux/

CFLAGS = -Wall -Wextra -Werror

NAME =	so_long

DIR_INC = -I ./includes/

SRCS =	so_long.c \

SRCS_DIR = ./srcs

DIR_OBJ = 	obj

OBJS = $(addprefix $(DIR_OBJ)/, ${SRCS:.c=.o})

DEPS = $(OBJS:.o=.d)

-include $(DEPS)

all:	${NAME}

${NAME}: ${OBJS}
		${CC} $(DIR_INC) ${OBJS} -o ${NAME} -L $(PATH_MLX) -lmlx -lX11 -lXext

$(DIR_OBJ)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DIR_INC) -c -o $@ $< -MMD

clean:
		rm -rf ${DIR_OBJ}

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY:	all clean fclean re