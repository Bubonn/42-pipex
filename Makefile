SRCS			= pipex.c pid.c ft_putstr_fd.c ft_split.c ft_strjoin.c \
				  ft_strnstr.c ft_strlen.c\

SRCS_BONUS		= pipex_bonus.c pid_bonus.c ft_putstr_fd.c ft_split.c ft_strjoin.c \
				  ft_strnstr.c get_next_line.c get_next_line_utils.c ft_strlen.c \
				  ft_strcmp.c ft_strncmp.c here_doc.c loop_wait.c

SRCS_DIR		= srcs/

BONUS_DIR		= srcs_bonus/


SRCS_PATH	 	= $(SRCS:%=$(SRCS_DIR)%)

SRCS_B_PATH 	= $(SRCS_BONUS:%=$(BONUS_DIR)%)

OBJS		 	= $(SRCS_PATH:%.c=%.o)

OBJS_BONUS		= $(SRCS_B_PATH:%.c=%.o)
#OBJS_BONUS		= $(SRCS_B_PATH:.c=.o)

PRINTF_DIR		= -C ft_printf --no-print-directory

LIBRARY			= ./ft_printf/libftprintf.a

NAME			= pipex

NAME_BONUS		= pipex_bonus

RM		 		= rm -f

CC				= cc -Wall -Wextra -Werror

all:			$(NAME)

bonus:			$(NAME_BONUS)


$(NAME):		$(OBJS)
					$(MAKE) $(PRINTF_DIR)
					$(CC) -I include $(SRCS_PATH) $(LIBRARY) -o $(NAME)

$(NAME_BONUS):	$(OBJS_BONUS)
					$(MAKE) $(PRINTF_DIR)
					$(CC) $(SRCS_B_PATH) $(LIBRARY) -o $(NAME_BONUS)
#					$(CC) -I include $(SRCS_B_PATH) $(LIBRARY) -o $(NAME)

clean:
					$(MAKE) clean $(PRINTF_DIR)
					${RM} ${OBJS} ${OBJS_BONUS}

fclean:			clean
					$(MAKE) fclean $(PRINTF_DIR)
					$(RM) $(NAME) $(NAME_BONUS)

re:				fclean ${NAME} 


#rebonus:		fclean ${NAME_BONUS}

.PHONY:			all clean fclean re bonus rebonus
