#ifndef BSQ_H
#define BSQ_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define MAX_BUFFER 1024
#define STDIN 0
#define STDOUT 1
#define STDERR 2
#define MAPERROR "Map Erro\n"

typedef struct s_find
{
    int x;
    int y;
    int max;
    char **clone;
} t_find;

typedef struct s_map
{
    char **map;
    int size;
    char emp;
    char obs;
    char full;
} t_map;

char **malloc_map(int size);

int ft_atoi(char *str);
int ft_is_duple(t_map *map);
int is_space(char ch);
int non_printable(char *str);
int ft_strlen(char *str);
void ft_strcpy(char *dest, char *src);
int numeric(char ch);
int first_line_exp(char *line, t_map *map);
int read_first_line(int fd, t_map *map);
t_map *read_map(char *filename);
int set_map(char *filename, t_map *map);
void printerror(void);
int bsq(char *filename);
void print_map(t_map *map);
int find_min(int west, int north, int west_north);
int find_bsq(t_map *map, t_find *find);
void fill_bsq(t_find find, t_map *map);
void map_free(int size, char **map);
t_find clone_map(t_map *map);
int start_bsq(t_map *map);

char **malloc_map(int size);
int valid_map(int fd, t_map *map);

t_map *std_read_map();
int stdbsq(void);
int std_read_first_line(t_map *map);
int std_set_map(t_map *map);
#endif
