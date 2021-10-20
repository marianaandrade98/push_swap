NAME	= push_swap

RM		= rm -f

FLAGS	= -Wall -Werror -Wextra	-g

LIBFT	= ./libft/libft.a

SRCS	= main.c main_utils.c main_utils1.c $(COMMON)
OBJS	= $(SRCS:.c=.o)

COMMON	= reverse.c rotate.c swap.c push.c utils.c

CHECKER	= checker
BONUS	= checker.c \
			$(COMMON)
OBJS_B	= $(BONUS:.c=.o)

mandatory:	$(NAME)
bonus:		$(CHECKER)

$(NAME):	$(OBJS)
		$(MAKE) bonus -C libft
		gcc $(OBJS) $(FLAGS) $(LIBFT) -o $(NAME)

all: $(NAME) $(CHECKER)

$(CHECKER):	$(OBJS_B)
		$(MAKE) bonus -C libft
		gcc $(OBJS_B) $(FLAGS) $(LIBFT) -o $(CHECKER)
clean:
			$(RM) $(OBJS) $(OBJS_B)
			$(MAKE) clean -C libft 

fclean:		clean
			$(RM) $(OBJS) $(OBJS_B) $(NAME) $(CHECKER)
			$(MAKE) fclean -C libft 
re:			fclean all

.PHONY: all, clean, fclean, re