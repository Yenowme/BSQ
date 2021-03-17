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

void printerror(void)
{
	write(STDERR, MAPERROR, ft_strlen(MAPERROR));
}

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

int stdbsq(void)
{
	t_map *map;

	if ((map = std_read_map()) == 0)
		return (0);
	if (start_bsq(map) == 0)
		return (0);
	return (1);
}

int bsq(char *filename)
{
	t_map *map;

	if (filename == 0)
		return (0);
	else if ((map = read_map(filename)) == 0)
		return (0);
	printf("%d%c%c%c\n", map->size, map->emp, map->obs, map->full);
	if (start_bsq(map) == 0)
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == 1)
	{
		if ((stdbsq() == 0))
			printerror();
	}
	else
	{
		while (i < argc)
		{
			if ((bsq(argv[i++]) == 0))
				printerror();
		}
	}
	return (0);
}
