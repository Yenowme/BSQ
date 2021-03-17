
#include "bsq.h"

char **malloc_map(int size)
{
	char **temp;
	int i;

	i = -1;
	temp = (char **)malloc(sizeof(char *) * size + 1);
	if (!temp)
		return (0);
	while (++i < size)
	{
		temp[i] = (char *)malloc(sizeof(char) * size + 1);
		if (!temp[i])
			return (0);
	}
	return (temp);
}

int valid_map(int fd, t_map *map)
{
	char buf;
	int i;
	int j;

	i = 0;
	j = 0;

	while ((read(fd, &buf, 1)))
	{

		if (buf == '\n')
		{
			i++;
			if (j != map->size)
				return (0);
			j = 0;
		}
		else if (buf == map->emp || buf == map->obs)
			j++;
		else
			return (0);
	}

	if (close(fd) == -1)
		return (0);

	if (i != map->size)
		return (0);
	return (1);
}
