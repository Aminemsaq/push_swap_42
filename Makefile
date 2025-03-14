NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Werror -Wextra
RM      = rm -rf

INCLUDE = push_swap.h
INCLUDE_2 = /libft/libft.h

SRC     = main.c utils_join.c utils_parsing.c utils_convert_int.c init_push_swap.c utils_stack.c push_instructions.c swap_instructions.c rotate_instructions.c reverse_rotate_instructions.c utils_algo.c utils_indexing.c
OBJ     = $(SRC:.c=.o)

LIBFT_DIR = ./libft
LIBFT     = /libft/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIBFT) 
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft	 -o $(NAME)

$(LIBFT): 
	@make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	$(RM) $(OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all
