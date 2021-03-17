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
        if (is_space(str[i]))
            i++;
        else if (str[i] == '+') //애매허다
            i++;
        else if (numeric(str[i]))
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
