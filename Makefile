NAME := push_swap
FLAGS := -Wall -Werror -Wextra
CC := gcc

DIR_OBJ := obj
HEADERS := src/get_next_line.h \
			src/push_swap.h \
			libft/libft.h

LIBFT_DIR := libft
LIBFT_LIB := $(addprefix $(LIBFT_DIR)/, libft.a)

DIR_SRC := src
SRC:= case_I.c \
		check.c \
		error.c \
		free.c \
		instr.c \
		main.c \
		sort_big.c \
		sort_min.c \
		stk_op_1.c \
		stk_op_2.c \
		stk_op_3.c \
		stk_op_4.c \
		utils.c \
		get_next_line.c

OBJ := $(addprefix $(DIR_OBJ)/,$(SRC:.c=.o))

INCLUDE := -I $(LIBFT_DIR) -I $(DIR_SRC)

all: $(DIR_OBJ) $(NAME)

$(DIR_OBJ):
	mkdir -p $(DIR_OBJ)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(NAME):  $(HEADERS) $(OBJ)
	make -C $(LIBFT_DIR) all
	$(CC) $(OBJ) -o $@ $(LIBFT_LIB)

clean:
	rm -rf $(DIR_OBJ)
	rm -f inst.log ps_numb
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

test: all
	python3 gen.py > ps_numb
	./push_swap -f ps_numb > inst.log

.PHONY : all clean fclean re test