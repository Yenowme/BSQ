#include "bsq.h"

int first_line_exp(char *line, t_map *map)
{
    int i;

    i = ft_strlen(line);
    if (i < 4)
        return (0);
    map->full = line[--i];
    map->obs = line[--i];
    map->emp = line[--i];
    if ((ft_is_duple(map) == 0))
        return (0);
    line[i] = 0;
    map->size = ft_atoi(line);
    if (map->size == 0)
        return (0);
    return (1);
}

int read_first_line(int fd, t_map *map)
{
    int i;
    char *line;

    line = (char *)malloc(sizeof(char) * MAX_BUFFER + 1);
    if (!line)
        return (0);
    i = 0;
    while ((read(fd, &line[i], 1)))
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

t_map *read_map(char *filename)
{
    int fd;
    t_map *map;

    if ((fd = open(filename, O_RDONLY)) == -1)
        return (0);
    if (!(map = (t_map *)malloc(sizeof(t_map))))
        return (0);
    if (read_first_line(fd, map) == 0)
        return (0);
    if (valid_map(fd, map) == 0)
        return (0);
    if (set_map(filename, map) == 0)
        return (0);
    if (close(fd))
        return (0);
    return (map);
}

void first(int fd)
{
    char ch;
    while (read(fd, &ch, 1))
        if (ch == '\n')
            return;
}

int set_map(char *filename, t_map *map)
{
    int i;
    int j;
    int fd;
    char buf;

    j = 0;
    i = 0;
    map->map = malloc_map(map->size);
    if (!map->map)
        return (0);
    if ((fd = open(filename, O_RDONLY)) == -1)
        return (0);
    first(fd);

    while (read(fd, &buf, 1))
        if (buf == '\n')
        {
            map->map[i][j] = 0;
            i++;
            j = 0;
        }
        else
            map->map[i][j++] = buf;
    map->map[i] = 0;
    return (1);
}
