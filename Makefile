SRCS_DIR = srcs

OBJS_DIR = objs

SRCS	:=	$(shell find srcs/*.c -exec basename \ {} \;)
SRCS_BUILT_IN	:=	$(shell find srcs/built_in/*.c -exec basename \ {} \;)
SRCS_ENV	:=	$(shell find srcs/env/*.c -exec basename \ {} \;)
SRCS_EXEC	:=	$(shell find srcs/exec/*.c -exec basename \ {} \;)
SRCS_PARSING	:=	$(shell find srcs/parsing/*.c -exec basename \ {} \;)
SRCS_SIGNAL	:=	$(shell find srcs/signal/*.c -exec basename \ {} \;)

OBJS = ${patsubst %.c,${OBJS_DIR}/%.o,${SRCS}}
OBJS_BUILT_IN = ${patsubst %.c,${OBJS_DIR}/%.o,${SRCS_BUILT_IN}}
OBJS_ENV = ${patsubst %.c,${OBJS_DIR}/%.o,${SRCS_ENV}}
OBJS_EXEC = ${patsubst %.c,${OBJS_DIR}/%.o,${SRCS_EXEC}}
OBJS_PARSING = ${patsubst %.c,${OBJS_DIR}/%.o,${SRCS_PARSING}}
OBJS_SIGNAL = ${patsubst %.c,${OBJS_DIR}/%.o,${SRCS_SIGNAL}}

HEADERS = minishell.h

LIB = ./libft/libft.a

NAME = minishell

# CC = gcc -fsanitize=address -g3
CC = gcc
# make && valgrind --suppressions=./suppres.txt ./minishell
CFLAGS = -Werror -Wall -Wextra

# -- RULES -- #

${NAME}: ${LIB} ${OBJS_DIR} ${OBJS} ${OBJS_BUILT_IN} ${OBJS_ENV} ${OBJS_EXEC} ${OBJS_PARSING} ${OBJS_SIGNAL} ${HEADERS}
	@${CC} ${CFLAGS} ${OBJS} ${OBJS_BUILT_IN} ${OBJS_ENV} ${OBJS_EXEC} ${OBJS_PARSING} ${OBJS_SIGNAL} ${LIB} -L/usr/local/lib -I/usr/local/include -lreadline -ltinfo -o ${NAME}
	@echo "\033[32m$ ${NAME} compiled !"
	@echo "----------------------------\033[0m"

debug: ${LIB} ${OBJS_DIR} ${OBJS} ${OBJS_BUILT_IN} ${OBJS_ENV} ${OBJS_EXEC} ${OBJS_PARSING} ${OBJS_SIGNAL} ${HEADERS}
	@${CC} ${CFLAGS} -fsanitize=address -g3 ${OBJS} ${OBJS_BUILT_IN} ${OBJS_ENV} ${OBJS_EXEC} ${OBJS_PARSING} ${OBJS_SIGNAL} ${LIB} -L/usr/local/lib -I/usr/local/include -lreadline -ltinfo -o ${NAME}
	@echo "\033[32m$ ${NAME} compiled !"
	@echo "----------------------------\033[0m"

all: ${NAME}

${LIB}:
	@make -sC ./libft

$(OBJS_DIR):
	@mkdir -p ${OBJS_DIR}
	@echo "\033[33mcompiling ${NAME}..."

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@${CC} ${CFLAGS} -I. -c $< -o $@

${OBJS_DIR}/%.o: srcs/built_in/%.c
	@${CC} ${CFLAGS} -I. -c $< -o $@

${OBJS_DIR}/%.o: srcs/env/%.c
	@${CC} ${CFLAGS} -I. -c $< -o $@

${OBJS_DIR}/%.o: srcs/exec/%.c
	@${CC} ${CFLAGS} -I. -c $< -o $@

${OBJS_DIR}/%.o: srcs/parsing/%.c
	@${CC} ${CFLAGS} -I. -c $< -o $@

${OBJS_DIR}/%.o: srcs/signal/%.c
	@${CC} ${CFLAGS} -I. -c $< -o $@

clean:
	@rm -rf ${OBJS_DIR}
	@echo "\033[32mclean !\033[0m"

fclean: clean
	@make fclean -sC ./libft
	@rm -f ${NAME}

re: fclean all

.PHONY:	all clean fclean re
