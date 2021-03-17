#ifndef BSQ_H
#define BSQ_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_BUFFER 1024
#define STDIN 0
#define STDOUT 1
#define STDERR 2

typedef struct s_map
{
    char **map;
    int size;
    char emp;
    char obs;
    char full;
} t_map;

int ft_atoi(char *str) int ft_is_duple(t_map *map);
int ft_is_duple(t_map *map);
int is_space(char ch);
int non_printable(char *str);
int ft_strlen(char *str);
void ft_strcpy(char *dest, char *src);
int numeric(char ch);

#endif
