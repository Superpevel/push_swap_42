SRCS=		main.c helpers.c

CC=		gcc

NAME=		push_swap

CFLAGS +=	
CFLAGS +=	-ansi -pedantic
CFLAGS +=	-I.

OBJS=		$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -g

clean:
	rm -rvf $(OBJS)

fclean:		clean
	rm -rvf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re