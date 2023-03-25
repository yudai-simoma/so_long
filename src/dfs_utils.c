/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:40:11 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/25 22:26:01 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_move_up(t_cell *a_cell, t_stack *a_stack,
	t_cell *a_next, t_map *a_map)
{
	// if (a_next->y == 0)
	// 	return 0;
	/* 現在探索中のマスから辿れる次の探索候補をスタックに格納 */
	if (ft_check(a_map, a_next->x, a_next->y - 1))
	{
		a_cell->x = a_next->x;
		a_cell->y = a_next->y - 1;
		if (a_map->map_str[a_cell->x][a_cell->y] != 'E') {
			a_map->map_str[a_cell->x][a_cell->y] = '2';
		}
		ft_push(a_stack, a_cell);
		return 1;
	}
	return 0;
}

int	ft_check_move_down(t_cell *a_cell, t_stack *a_stack,
	t_cell *a_next, t_map *a_map)
{
	// if (a_next->y == a_map->column)
	// 	return 0;
	/* 現在探索中のマスから辿れる次の探索候補をスタックに格納 */
	if (ft_check(a_map, a_next->x, a_next->y + 1))
	{
		a_cell->x = a_next->x;
		a_cell->y = a_next->y + 1;
		if (a_map->map_str[a_cell->x][a_cell->y] != 'E') {
			a_map->map_str[a_cell->x][a_cell->y] = '2';
		}
		ft_push(a_stack, a_cell);
		return 1;
	}
	return 0;
}

int	ft_check_move_right(t_cell *a_cell, t_stack *a_stack,
	t_cell *a_next, t_map *a_map)
{
	// if (a_next->x == a_map->record)
	// 	return 0;
	/* 現在探索中のマスから辿れる次の探索候補をスタックに格納 */
	if (ft_check(a_map, a_next->x + 1, a_next->y))
	{
		a_cell->x = a_next->x + 1;
		a_cell->y = a_next->y;
		if (a_map->map_str[a_cell->x][a_cell->y] != 'E') {
			a_map->map_str[a_cell->x][a_cell->y] = '2';
		}
		ft_push(a_stack, a_cell);
		return 1;
	}
	return 0;
}

int	ft_check_move_left(t_cell *a_cell, t_stack *a_stack,
	t_cell *a_next, t_map *a_map)
{
	// if (a_next->x == 0)
	// 	return 0;
	/* 現在探索中のマスから辿れる次の探索候補をスタックに格納 */
	if (ft_check(a_map, a_next->x - 1, a_next->y))
	{
		a_cell->x = a_next->x - 1;
		a_cell->y = a_next->y;
		if (a_map->map_str[a_cell->x][a_cell->y] != 'E') {
			a_map->map_str[a_cell->x][a_cell->y] = '2';
		}
		ft_push(a_stack, a_cell);
		return 1;
	}
	return 0;
}
