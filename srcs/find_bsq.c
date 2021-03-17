/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:41:47 by yejeong           #+#    #+#             */
/*   Updated: 2021/03/17 20:39:40 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void print_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		write(1, map->map[i], map->size); //each end of line..?
		write(1, "\n", 1);
		i++;
	}
}

int find_min(int west, int north, int west_north)
{
	int min;

	min = west > north ? north : west;
	min = min > west_north ? west_north : min;
	return (min);
}

//꽉찬 맵 받는다
int find_bsq(t_map *map, t_find *find) //구조체에 최댓값
{
	int i;
	int j;

	i = 0;
	find->max = 0;
	while (++i < map->size) //1,1부터 개행빼고 검사
	{
		j = 0;
		while (++j < map->size) //1,1부터 개행빼고 검사
		{
			if (find->clone[i][j] == '1') //현재가 경로라면
			{
				find->clone[i][j] = find_min(find->clone[i][j - 1], find->clone[i - 1][j], find->clone[i - 1][j - 1]) + 1; //최소값 + 1
				if (find->max < find->clone[i][j] - '0')
				{
					find->max = find->clone[i][j] - '0';
					find->x = i;
					find->y = j;
				}
			}
		}
	}
	return (find->max);
}

void fill_bsq(t_find find, t_map *map)
{
	int i;
	int j;
	int max;

	max = find.max;
	i = find.x;
	while (i > find.x - find.max) //max만큼 이동
	{
		j = find.y;
		while (j > find.y - find.max) //max 만큼 이동
		{
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
	while (i < size)
	{
		free(map[i]);
	}
	free(map);
}

t_find clone_map(t_map *map)
{
	t_find find;
	int i;
	int j;

	i = -1;
	find.clone = malloc_map(map->size); //map 말록 동일하게
	while (++i < map->size)
	{
		j = -1;
		while (++j < map->size)
		{
			if (map->map[i][j] == map->emp)
				find.clone[i][j] = '1';
			else if (map->map[i][j] == map->obs)
				find.clone[i][j] = '0';
		}
		map->map[i][j] = 0;
	}
	return (find);
}

int start_bsq(t_map *map)
{
	t_find find;
	int rt;

	rt = 1;
	find = clone_map(map); // find->clone 에 맵 클론하기
	if (find_bsq(map, &find) == 0)
		rt = 0;
	else
	{						 //숫자 바꾸고 bsq찾기:w
		fill_bsq(find, map); //맵 채워넣기
		print_map(map);		 //맵 프린트 하기
	}
	map_free(map->size, map->map); //맵 해재
	map_free(map->size, find.clone);
	free(map);
	return (rt);
}
