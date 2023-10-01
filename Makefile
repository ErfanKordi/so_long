NAME	= so_long
SRCS	= main.c readmap.c exit_check.c graphics.c controller.c
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror
GETNEXTLINE = get_next_line/*c
LIBRARY = -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX = minilibx/
LIBFTDIR = My_C_Library
LIBFT	= $(LIBFTDIR)/libft.a

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	make -C $(MINILIBX)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(SRCS) -L$(LIBFTDIR) -lft $(GETNEXTLINE) $(LIBRARY) -o $(NAME)

clean:
	$(RM) $(OBJS)


fclean:	clean
	make clean -C $(MINILIBX)
	make clean -C $(LIBFTDIR)
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
