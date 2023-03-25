/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:40:11 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/25 11:53:12 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_move_up(t_cell *a_cell, t_stack *a_stack,
	t_cell *a_next, t_map *a_map)
{
	/* 現在探索中のマスから辿れる次の探索候補をスタックに格納 */
	if (ft_check(a_map, a_next->x, a_next->y - 1))
	{
		a_cell->x = a_next->x;
		a_cell->y = a_next->y - 1;
		push(a_stack, a_cell);
	}
}

void	ft_check_move_down(t_cell *a_cell, t_stack *a_stack,
	t_cell *a_next, t_map *a_map)
{
	/* 現在探索中のマスから辿れる次の探索候補をスタックに格納 */
	if (ft_check(a_map, a_next->x, a_next->y + 1))
	{
		a_cell->x = a_next->x;
		a_cell->y = a_next->y + 1;
		push(a_stack, a_cell);
	}
}

void	ft_check_move_right(t_cell *a_cell, t_stack *a_stack,
	t_cell *a_next, t_map *a_map)
{
	/* 現在探索中のマスから辿れる次の探索候補をスタックに格納 */
	if (ft_check(a_map, a_next->x + 1, a_next->y))
	{
		a_cell->x = a_next->x + 1;
		a_cell->y = a_next->y;
		push(a_stack, a_cell);
	}
}

void	ft_check_move_left(t_cell *a_cell, t_stack *a_stack,
	t_cell *a_next, t_map *a_map)
{
	/* 現在探索中のマスから辿れる次の探索候補をスタックに格納 */
	if (ft_check(a_map, a_next->x - 1, a_next->y))
	{
		a_cell->x = a_next->x - 1;
		a_cell->y = a_next->y;
		push(a_stack, a_cell);
	}
}
