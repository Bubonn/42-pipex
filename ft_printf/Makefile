SRCS		= ft_printf.c ft_putchar.c ft_putstr.c ft_strlen.c ft_putnbr.c ft_putnbr_hexa.c \
			  ft_print_addr.c ft_putnbr_bis.c ft_memset.c

OBJS	 	= ${SRCS:.c=.o}

NAME	 	= libftprintf.a

RM		 	= rm -f

CC			= cc -Wall -Wextra -Werror

all:		${NAME}

test:
			${CC} ${SRCS}

$(NAME):	${OBJS}
				ar rcs ${NAME} ${OBJS}

clean:
				${RM} ${OBJS}

fclean:		clean
				${RM} ${NAME}

re:			fclean ${NAME}

.PHONY:		all clean fclean re bonus
