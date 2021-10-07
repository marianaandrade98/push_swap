NAME	= push_swap

RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra	-g

LIBFT	= ./libft/libft.a

SRCS	= main.c reverse.c rotate.c swap.c push.c validations.c sorting.c \
			algo_5_utils.c median.c algo_500_utils.c algo_500_utils_1.c \
			rotate_choice.c


OBJS	= $(SRCS:.c=.o)
all : $(NAME)

$(NAME):	$(OBJS)
		$(MAKE) bonus -C libft
		gcc $(OBJS) $(FLAGS) $(LIBFT) -o $(NAME)


clean:
			$(RM) $(OBJS)
			$(MAKE) clean -C libft 

fclean:		clean
			$(RM) $(OBJS) $(NAME)
			$(MAKE) fclean -C libft 
re:			fclean all

.PHONY: all, clean, fclean, re