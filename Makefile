
NAME        := push_swap
CC        := gcc
FLAGS    := -Wall -Wextra -Werror 
SRCS        :=      error_check.c \
                          helper_func.c \
                          main.c \
                          push_swap.c \
                          rule_p.c \
                          rule_r.c \
                          rule_rr.c \
                          rule_s.c \
                          util1.c \
                          util2.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

SRCS        :=      error_check.c \
                          helper_func.c \
                          main.c \
                          push_swap.c \
                          rule_p.c \
                          rule_r.c \
                          rule_rr.c \
                          rule_s.c \
                          util1.c \
                          util2.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}
