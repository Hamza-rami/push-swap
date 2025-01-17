NAME = push_swap

SRC = best_move.c ft_atoi.c ft_split.c if_sorted.c join.c lisub.c min_move.c pa.c \
		parce.c part_stack.c pb.c ra.c rb.c rr.c rra.c rrb.c rrr.c sa.c sb.c smalle_stack.c \
		ss.c stack.c push_swap.c
INC = push_swap.h
OBJS = ${SRC:.c=.o}
ARC = ar -rc
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