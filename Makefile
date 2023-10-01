NAME	= so_long
SRCS	= main.c readmap.c exit_check.c graphics.c controller.c
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address
GETNEXTLINE = get_next_line/*c
LIBRARY = -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX = minilibx/
PRINTFDIR = ft_printf
PRINTF = $(PRINTFDIR)/libftprintf.a
LIBFTDIR = My_C_Library/
LIBFT	= $(LIBFTDIR)/libft.a

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT) $(PRINTF)
	make -C $(MINILIBX)
	make -C $(LIBFTDIR)
	make -C $(PRINTFDIR)
	$(CC) $(CFLAGS) $(SRCS) -L$(PRINTFDIR) -lftprintf -L$(LIBFTDIR) -lft $(GETNEXTLINE) $(LIBRARY) -o $(NAME)

clean:
	$(RM) $(NAME)


fclean:	clean
	make clean -C $(MINILIBX)
	make clean -C $(PRINTFDIR)
	make clean -C $(LIBFTDIR)
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
