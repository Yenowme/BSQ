#include "bsq.h";

int stdinput()
{
	return (0);
}

int first_line_exp(char *line, t_map *map)
{
	int i;

	i = ft_strlen(line);
	if (i <= 3)
		return (0);
	//10tes  01234
	map->full = line[--i];
	map->obs = line[--i];
	map->emp = line[--i];
	if ((ft_is_duple(map) == 0))
		return (0);
	line[i] = 0;
	map->size = ft_atoi(line);
	if (map->x == 0)
		return (0);
	return (1);
}

int read_first_line(int fd, t_map *map)
{
	int i;
	char *line;

	line = (char *)malloc(sizeof(char) * MAX_BUFFER + 1);
	i = 0;
	while ((read(fd, &line[i], 1)))
	{
		if (line[i] == '\n')
		{
			line[i] = 0;
			if (non_printable(line))
				return (0);
			if (first_line_exp(line, map) == 0)
				return (0);
			return (1);
		}
		i++;
	}
	return (1);
}

t_map *read_map(char *filename)
{
	int fd;
	t_map *map;

	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		printf("File Error\n");
		return (0);
	}
	if (!(map = (t_map *)malloc(sizeof(t_map))))
	{
		printf("Map Error\n");
		return (0);
	}
	if (read_first_line(fd, map) == 0)
		return (0);
	//valid_map(fd, map) -> 에러 처리
	//set_map(filename, mao)
	close(fd);
	return (map);
}

int bsq(char *filename)
{
	t_map *map;

	if ((map = read_map(filename)) == 0)
		return (0);
	//if (start_bsq(map) == 0)
	//return (0);
	return (1);
}

int main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == 1)
		stdinput();
	else
	{
		while (i < argc)
		{
			if ((bsq(argv[i++]) == 0))
				printf("Map Error\n");
		}
	}
}
