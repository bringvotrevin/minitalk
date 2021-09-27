.PHONY : bonus all claen fclean re
NAME = client
NAME2 = server
SRCDIR = srcs/
CC = gcc
RM = rm -rf
WFLAGS = -Wall -Werror -Wextra
DEBUGFLAGS = -g -fsanitize=address
CFLAGS = $(WFLAGS) $(INCFLAGS) #$(DEBUGFLAGS)

SRC1 = client.c \
	   minitalk_util.c \
	   ft_atoi.c

SRC2 = server.c \
	   minitalk_util.c

BRC1 = client_bonus.c \
	   minitalk_util_bonus.c \
	   ft_atoi_bonus.c

BRC2 = server_bonus.c \
	   minitalk_util_bonus.c

ifdef WITH_BONUS
	SRC1 = $(BRC1)
	SRC2 = $(BRC2)
endif

SRCS1 =	$(addprefix $(SRCDIR), $(SRC1))
SRCS2 = $(addprefix $(SRCDIR), $(SRC2))

all : ${NAME} ${NAME2} 

${NAME} :
			$(CC) $(CFLAGS) $(SRCS1) -o $(NAME)

${NAME2} :
			$(CC) $(CFLAGS) $(SRCS2) -o $(NAME2)

bonus : 
			make WITH_BONUS=1 all

clean :
			${RM} ${OBJS1} ${OBJS2}

fclean :	clean
			${RM} ${NAME} ${NAME2}

re :		fclean all
