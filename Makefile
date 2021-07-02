NAME	= push_swap
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra
INCLUDE	= push_swap.h

SRCS	= main.c swap.c push.c rotate.c reverse.c

OBJS	= $(SRCS:.c=.o)

all : $(NAME)

$(NAME):    $(OBJS) $(INCLUDE)
			ar -rcs $(NAME) $(OBJS)
			ranlib  $(NAME)

.c.o:
			$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJS) $(BONUS_O)

fclean:		clean
			$(RM) $(NAME)
re:			fclean all

.PHONY: all, clean, fclean, re