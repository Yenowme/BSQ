#include "bsq.h"

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
	system("leaks BSQ > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
	return (0);
}
