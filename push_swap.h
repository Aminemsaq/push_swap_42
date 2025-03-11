#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <../libft/libft.h>
#include <limits.h>

typedef struct
{
    int *numbers_int;
    char *long_number;
    char **long_split;
    int size;
} Data;

typedef struct s_node
{
    int value;
    struct s_node *next;
} t_node;

typedef struct s_stack
{
    t_node *top;
    int size;
} t_stack;

int joining(int ac, char **av, Data *data);
void free_double(char **tbl);
int help_join(char *number);
int ft_isvalid(char c);
int ft_parsing(Data *data);
int convert_to_int(Data *data);
int check_dupl(int *numbers_int, int size);
int check_sorted(int *numbers_int, int size);
void init_push_swap(Data data);
t_stack *init_stack();
void push(t_stack *stack, int value);
int pop(t_stack *stack);
void print_stack(t_stack *stack);
void free_stack(t_stack *stack);
void free_data(Data *data);

#endif