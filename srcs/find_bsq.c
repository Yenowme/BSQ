/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:41:47 by yejeong           #+#    #+#             */
/*   Updated: 2021/03/18 02:33:59 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int find_bsq(t_map *map, t_find *find)
{
	int i;
	int j;

	i = 0;
	find->max = 0;
	while (++i < map->size)
	{
		j = 0;
		while (++j < map->size)
		{
			if (find->clone[i][j] == '1')
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
	while (i > find.x - find.max)
	{
		j = find.y;
		while (j > find.y - find.max)
		{
			map->map[i][j] = map->full;
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
	find.clone = malloc_map(map->size);
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
	find = clone_map(map);
	if (map->size == 1)
		one_print(map->full);
	else if (find_bsq(map, &find) == 0)
		rt = 0;
	else
	{
		fill_bsq(find, map);
		print_map(map);
	}
	map_free(map->size, map->map);
	map_free(map->size, find.clone);
	free(map);
	return (rt);
}
