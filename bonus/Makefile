NAME = checker

SRC = apply_move.c check_move.c cheker.c ft_add_back.c ft_atoi.c ft_split.c \
		get_next_line.c get_next_line_utils.c join_bonus.c move_pa.c move_rr.c \
		move_rrr.c move_ss.c parce_bonus.c stack.c utlise_bonus.c holdStacks_bonus.c
INC = push_swap_bonus.h
OBJS = ${SRC:.c=.o}
CC = cc -Wall -Werror -Wextra
RM = rm -f

%.o: %.c ${INC}
	${CC} -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${OBJS} -o ${NAME} 

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} 

re: fclean all