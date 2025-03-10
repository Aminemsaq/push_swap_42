#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <../libft/libft.h>
#include <limits.h>

typedef struct {
    char *long_number;
    char **numbers;
    long **numbers_int;
} 	Data;

char **joining(int ac, char **av);
void free_double(char **tbl);
int help_join(char *number);
int ft_isvalid(char c);
int ft_parsing(char **numbers);
long *convert_to_int(char **numbers);
int check_dupl(long *numbers_int, int size);
int check_sorted(long *numbers_int, int size);

#endif