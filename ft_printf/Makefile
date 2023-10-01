NAME	= libftprintf.a
SRCS	= ft_printf.c c.c d.c p.c s.c u.c x.c
OBJS	= $(SRCS:.c=.o)
CC		= cc
RM		= rm -f

all:	$(NAME)

$(NAME):$(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:	all clean fclean re bonus
