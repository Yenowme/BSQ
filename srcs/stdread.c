#include "bsq.h"

int std_read_first_line(t_map *map)
{
    int i;
    char *line;

    line = (char *)malloc(sizeof(char) * MAX_BUFFER + 1);
    if (!line)
        return (0);
    i = 0;
    while ((read(STDIN, &line[i], 1)))
    {
        if (line[i] == '\n')
        {
            line[i] = 0;
            if (non_printable(line) || first_line_exp(line, map) == 0)
            {
                free(line);
                return (0);
            }
            free(line);
            return (1);
        }
        i++;
    }
    free(line);
    return (0);
}

int std_set_map(t_map *map)
{
    int i;
    int j;
    char buf;

    j = 0;
    i = 0;
    map->map = malloc_map(map->size);
    if (!map->map)
        return (0);
    while (read(0, &buf, 1))
        if (buf == '\n')
        {
            if (j != map->size)
                return (0);
            map->map[i][j] = 0;
            i++;
            j = 0;
        }
        else if (buf == map->emp || buf == map->obs)
            map->map[i][j++] = buf;
        else
            return (0);
    map->map[i] = 0;
    return (1);
}

t_map *std_read_map()
{
    t_map *map;

    if (!(map = (t_map *)malloc(sizeof(t_map))))
        return (0);
    if (std_read_first_line(map) == 0)
        return (0);
    if ((std_set_map(map)) == 0)
        return (0);
    return (map);
}

