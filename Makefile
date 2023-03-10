NAME=fdf
CC=cc
FILES=fdf map_array draw_lines transformation point cartesian_map_array hooks draw_map destroy_map
SRC := $(addsuffix .c, $(FILES))
SRC := $(addprefix sources/, $(SRC))
OBJS = $(addsuffix .o, $(FILES))
PRINTF_PATH=lib/ft_printf
FLAGS=-I includes -I $(PRINTF_PATH)/includes -I $(PRINTF_PATH)/libft\
	  -Wall -Werror -Wextra
LIBS=$(PRINTF_PATH)/libftprintf.a
LIBS_FLAGS=-Llib/ft_printf -lftprintf -lm -Llib/minilibx-linux -lmlx_Linux -L/usr/lib -Ilib/minilibx-linux -lXext -lX11 -lz

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS_FLAGS) -o $(NAME)

$(OBJS): $(SRC) $(LIBS)
	$(CC) $(FLAGS) -c $(SRC)

$(LIBS):
	make -C $(PRINTF_PATH)

clean:
	make -C $(PRINTF_PATH)/ clean
	rm -rf $(OBJS)

fclean: clean
	make -C $(PRINTF_PATH)/ fclean
	rm -rf $(NAME)

re: fclean all
