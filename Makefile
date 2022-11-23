NAME	= minitalk

SERVER	= server

CLIENT	= client

CC		= cc

LIBFTPRINTF	= ft_printf/libftprintf.a

RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror

$(NAME):	server client

${SERVER}:	${LIBFT} server.c
			${CC} ${CFLAGS} server.c -o server ft_printf/libftprintf.a

${CLIENT}:	${LIBFT} client.c
			${CC} ${CFLAGS} client.c -o client ft_printf/libftprintf.a

${LIBFT}:
			make -C ./ft_printf/

bonus:		${SERVERB} ${CLIENTB}

all:		$(NAME)

clean:
			${RM} ${SERVER} ${CLIENT} ${SERVERB} ${CLIENTB}
			cd ft_printf && make clean

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re