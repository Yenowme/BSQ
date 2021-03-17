/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeong <yejeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:41:47 by yejeong           #+#    #+#             */
/*   Updated: 2021/03/17 16:41:04 by yejeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef	struct	s_find
{
	int x;
	int y;
	int max;
	char **clone;
}		t_find

void print_map(char **map) //맵 출력
{
	int i;

	i = 0;
	while (i < map->size)
	{
		write(1, map[i], map->size);
		write(1, "\n", 1);
		i++;
	}

}

int find_min(int west, int north, int west_north)
{
	int min;

	min = west > north ? north : west; 
	min = min > west_north ? west_nort : min;
	return (min)
}

//꽉찬 맵 받는다 
int find_bsq(t_map *map, t_find *find) //구조체에 최댓값 
{
	int i;
	int j;

	i = 0;
	find->max = 0;
	while(++i < map->size)//1,1부터 개행빼고 검사
	{
		j = 0;
		while(++j < map->size) //1,1부터 개행빼고 검사 
		{
			if (find->clone[i][j] == '1') //현재가 경로라면
			{
				find->clone[i][j] = find_min(find->clone[i][j - 1], find->clone[i - 1][j], find->clone[i - 1][j - 1]) + 1;//최소값 + 1
				if (find->max < map->map[i][j])
				{
					find->max = map->map[i][j]; //최대값 갱신
					find->x = i;//현재위치 저
					find->y = j;
				}
			}
		}
	}
	return (find->max);
}

void	fill_bsq(t_find *find, t_map *map)
{
	int i;
	int j;
	int max;

	max = find->max
	i = find->x;
	while (i > i - find->max)//max만큼 이동
	{
		j = find.y;
		while(j > j - find->max) //max 만큼 이동
		{기
			map->map[i][j] = map->full; //채우
			j--;
		}
		i--;
	}
}

void map_free(int size, char **map)
{
	int i;

	i = 0;
	while(i < size)//가로 해재
	{
		free(map[i]);
	}
	free(map);
}

t_find	*clone_map(t_map *map)
{
	t_find *find;
	int i;
	int j;

	j = -1;
	i = -1;
	find->map = malloc_map(map->size); //map 말록 동일하게
	while(++i < map->size)
	{
		while (++j < map->size)
		{
			if(map->map[i][j] == map->emp)
				find->clone[i][j] = '1';
			else if(map->map[i][j] == map->obs)
				find->clone[i][j] = '0';
		}
		map->map[i][j] = 0;
	}
}

int	start_bsq(t_map *map)
{
	t_find *find;

	find = clone_map(map); // find.clone 에 맵 클론하기
	if (find_bsq(map,find) == 0)
		return (0);//숫자 바꾸고 bsq찾기:w
	fill_bsq(find, map);//맵 채워넣기
	print_map(map->map);//맵 프린트 하기
	map_free(map->size, map->map); //맵 해재
	map_free(map->size, find->clone)

}

