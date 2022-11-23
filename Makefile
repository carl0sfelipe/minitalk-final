NAME	= minitalk

SERVER	= server

CLIENT	= client

CC		= cc

LIBFTPRINTF	= ft_printf/libftprintf.a

RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror

$(NAME):	all

all:		${SERVER} ${CLIENT}

${SERVER}:	
			make -C ./ft_printf
			${CC} ${CFLAGS} server.c ft_printf/libftprintf.a -o server 

${CLIENT}:	
			${CC} ${CFLAGS} client.c ft_printf/libftprintf.a -o client

clean:
			${RM} ${SERVER} ${CLIENT} ${SERVERB} ${CLIENTB}
			cd ft_printf && make fclean

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re