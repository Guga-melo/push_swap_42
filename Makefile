NAME = push_swap

CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
LIBFT	= ./libft/libft.a
SRCS	= ./src/push_swap.c \
	  ./src/exec_swap.c

OBJS	= $(SRCS: .c=.o)

$(NAME):	$(OBJS)
			make -C ./libft	
			cc $(OBJS) $(CFLAGS) $(LIBFT) -o $(NAME)

all:		$(NAME)

clean:
			make clean -C ./libft
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C ./libft
			$(RM) $(NAME)

re:
			fclean all

.PHONY:		all clean fclean re
