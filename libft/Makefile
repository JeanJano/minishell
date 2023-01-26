SRCSDIR	= srcs

OBJSDIR	= objs

SRCS	= $(shell find srcs/*.c -exec basename \ {} \;)

OBJS	= ${patsubst %.c,${OBJSDIR}/%.o,${SRCS}}

HEADERS	= libft.h get_next_line.h ft_printf.h

NAME	= libft.a

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

${NAME}:	${OBJSDIR} ${OBJS} ${HEADERS} Makefile
	@ar rcs ${NAME} ${OBJS}
	@echo "\033[32mlibft compiled !"

all:	${NAME}

$(OBJSDIR):
	@echo "\033[33mcompiling libft..."
	@mkdir ${OBJSDIR}

${OBJSDIR}/%.o: ${SRCSDIR}/%.c
	@${CC} ${CFLAGS} -I. -c $< -o $@

clean:
	@rm -rf ${OBJS} $(OBJSDIR)

fclean:	clean
	@rm -f ${NAME}

re: fclean all

.PHONY:	all clean fclean re
