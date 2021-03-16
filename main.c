#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define MAX_BUFFER 1024
#define STDIN 0
#define STDOUT 1
#define STDERR 2

typedef struct s_map{
	char	**map;
	int		x;
	int		y;
	char	emp;
	char	obs;
	char	full;
}	t_map;

typedef struct s_val{
	int g_idx;
}	g_val;

//string.c
int		is_space(char ch)
{
	if ((ch >= 9 && ch <= 13) || ch == ' ')
		return (1);
	return (0);
}

int		non_printable(char ch)
{
	if (ch < 32 || ch > 126)
		return (1);
	return (0);
}

int		ft_strlen(char *str)
{
	int		idx;

	idx = 0;
	while(str[idx])
		idx++;
	return (idx);
}

int		numeric(char ch)
{
//	if (ch >= '0' && ch <= '9')
	return (0);
}
//fileread.c
int		stdinput()
{
	return (0);
}

int		first_line_exp(char	*line, t_map	*map)
{
	int		idx;
	int		line_len;
	int		count;

	idx = 0;
	line_len = ft_strlen(line);
	count = 0;


	return (1);
}
int		first_line(int fd, t_map	*map)
{
	int		idx;
	char	*line;

	line = (char *)malloc(sizeof(char) * MAX_BUFFER + 1);
	idx = 0;
	while ((read(fd, &line[idx], 1)))
	{
		if (line[idx] == '\n')
		{
			line[idx] = 0;
			first_line_exp(line, map);
			//첫 라인 에러처리
			break;
		}
		idx++;
	}
	return (1);
}

t_map	*read_map(char *filename)
{
	int		fd;
	t_map	*map;

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
	first_line(fd, map);

	linea(fd, map)
	return (0);
}


int		file_input(char *filename)
{
	t_map	*map;
	int		i;

	if((map = read_map(filename)) == 0)
		return (0);

	return (1);
}


int main(int argc, char **argv)
{
	int		i;

	printf("%d\n",argc);
	i = 1;
	if (argc == 1)
		stdinput();
	else
	{
		while (i < argc)
		{
			if ((file_input(argv[i++]) == 0))
				printf("Map Error\n");
		}
	}
}
