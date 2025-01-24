NAME = push_swap
NAME_BNS = checker

SRC = mandatory/best_move.c mandatory/ft_atoi.c mandatory/ft_split.c mandatory/if_sorted.c mandatory/join.c mandatory/lisub.c mandatory/min_move.c mandatory/pa.c \
		mandatory/parce.c mandatory/part_stack.c mandatory/pb.c mandatory/ra.c mandatory/rb.c mandatory/rr.c mandatory/rra.c mandatory/rrb.c mandatory/rrr.c mandatory/sa.c mandatory/sb.c mandatory/smalle_stack.c \
		mandatory/ss.c mandatory/stack.c mandatory/push_swap.c mandatory/holdStacks.c \

SRC_BNS = bonus/apply_move.c bonus/check_move.c bonus/cheker.c bonus/ft_add_back.c bonus/ft_atoi.c bonus/ft_split.c \
		bonus/get_next_line.c bonus/get_next_line_utils.c bonus/join_bonus.c bonus/move_pa.c bonus/move_rr.c \
		bonus/move_rrr.c bonus/move_ss.c bonus/parce_bonus.c bonus/stack.c bonus/utlise_bonus.c bonus/holdStacks_bonus.c \

INC = mandatory/push_swap.h
INC_BNS = bonus/push_swap_bonus.h
OBJS = ${SRC:.c=.o}
OBJS_BNS = ${SRC_BNS:.c=.o}
CC = cc -Wall -Werror -Wextra
RM = rm -f

all: ${NAME}

mandatory/%.o: mandatory/%.c ${INC}
	${CC} -c $< -o $@

bonus/%.o: bonus/%.c ${INC_BNS}
	${CC} -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${OBJS} -o ${NAME} 

bonus:  ${OBJS_BNS}
	${CC} ${OBJS_BNS} -o ${NAME_BNS}

clean:
	${RM} ${OBJS} ${OBJS_BNS}

fclean: clean
	${RM} ${NAME} ${NAME_BNS}

re: fclean all