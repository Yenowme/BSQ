#include "bsq.h"

int ft_is_duple(t_map *map)
{
    if (map->emp == map->obs)
        return (0);
    if (map->emp == map->full)
        return (0);
    if (map->obs == map->full)
        return (0);
    return (1);
}

int ft_atoi(char *str)
{
    int i;
    int value;

    value = 0;
    i = 0;
    while (str[i])
    {
        while (is_space(str[i]))
            i++;
        if (str[i] == '+') //애매허다
            i++;
        if (numeric(str[i]))
            break;
        else
            return (0);
        i++;
    }
    while (str[i])
    {

        if (!numeric(str[i]))
            return (0);

        value *= 10;
        value += str[i] - '0';
        i++;
    }
    return (value);
}

void printerror(void)
{
    write(STDERR, MAPERROR, ft_strlen(MAPERROR));
}

int find_min(int west, int north, int west_north)
{
    int min;

    min = west > north ? north : west;
    min = min > west_north ? west_north : min;
    return (min);
}

void print_map(t_map *map)
{
    int i;

    i = 0;
    while (i < map->size)
    {
        write(1, map->map[i], map->size); //each end of line..?
        write(1, "\n", 1);
        i++;
    }
}
