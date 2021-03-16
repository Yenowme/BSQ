
char **malloc_map(int size)
{
	char **temp;
	int i;

	i = 0;
	temp = (char **)malloc(sizeof(char *) * size + 1);
	if (!temp)
		return (0);
	while (i < size)
	{
		temp[i] = (char *)malloc(sizeof(char) * size + 1);
	}
	return (temp);
}

void	set_map(char **map)
{
	//map에 값 넣기 
}

int		valid_map(int fd, t_map *map)
{
	char buf;
	int i;
	int j;

	i = 0;
	while ((read(fd, &buf, 1)))
	{
		if (buf == '\n')
		{
			i++;
			j = 0;
		}
		else if (buf == map->emp || buf == map->obs || buf == map->full)
			j++;
		else 
			return (0);
	}
	if (i != map->x || j != map->x)
		return (0);
 	if (!(map->map = malloc_map(map->x)))
		return (0);
	set_map(map->map);
}
