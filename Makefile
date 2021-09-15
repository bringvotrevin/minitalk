.PHONY : bonus all claen fclean re
NAME1 = client
NAME2 = server
SRCDIR = srcs/
CC = gcc
RM = rm -rf
WFLAGS = -Wall -Werror -Wextra
DEBUGFLAGS = -g -fsanitize=address
CFLAGS = $(WFLAGS) $(INCFLAGS) $(DEBUGFLAGS)

SRC1 = client.c \
	   minitalk_util.c \
	   ft_atoi.c

SRC2 = server.c \
	   minitalk_util.c

SRCS1 =	$(addprefix $(SRCDIR), $(SRC1))

SRCS2 = $(addprefix $(SRCDIR), $(SRC2))

OBJS1 = $(SRCS1:.c=.o)

OBJS2 = $(SRCS2:.c=.o)

${NAME1} : ${OBJS1}
			$(CC) $(CFLAGS) $(OBJS1) -o $(NAME1)

${NAME2} : ${OBJS2}
			$(CC) $(CFLAGS) $(OBJS2) -o $(NAME2)

all :		${NAME1} ${NAME2}

clean :
			${RM} ${OBJS1} ${OBJS2}

fclean :	clean
			${RM} ${NAME1} ${NAME2}

re :		fclean all
