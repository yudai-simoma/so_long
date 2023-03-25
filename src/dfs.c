/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 10:40:02 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/25 11:53:18 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//深さ優先探索
//ここからがDFSのソース

/* (i,j) が通過可能なマスかどうかを確認する関数 */
/*
 * 
 * 1が壁、2が通過したマス
 */
int	ft_check(t_map *a_map, int x, int y)
{
	if (a_map->map_str[y][x] == '1')
		return (0);
	if (a_map->map_str[y][x] == '2')
		return (0);
	return (1);
}

/* スタート(i,j)からゴールを探索する関数*/
int	ft_search(t_map *a_map, t_stack	*a_stack, t_cell *a_cell)
{
	t_cell	*r_next;

	while (1)
	{
		r_next = ft_pop(a_stack);
		if (r_next == NULL)
			return (0);
		if (a_map->map_str[r_next->y][r_next->x] == 'E')
			return (1);
		a_map->map_str[r_next->y][r_next->x] = '2';
		ft_check_move_up(a_cell, a_stack, r_next, a_map);
		ft_check_move_down(a_cell, a_stack, r_next, a_map);
		ft_check_move_right(a_cell, a_stack, r_next, a_map);
		ft_check_move_left(a_cell, a_stack, r_next, a_map);
	}
}

int	ft_map_path_check(t_map *a_map)
{
	t_stack	r_stack;
	t_cell	r_cell;

	ft_init_stack(&r_stack);
	/* 次の探索候補としてスタートのマスの情報をスタックに格納 */
	if (ft_check(a_map, a_map->start_x, a_map->start_y))
	{
		/* スタートのi座標*/
		r_cell.x = a_map->start_x;
		/* スタートのj座標*/
		r_cell.y = a_map->start_y;
		/* スタックにマスの情報を格納*/
		ft_push(&r_stack, &r_cell);
	}
	if (ft_search(a_map, &r_stack, &r_cell))
		return (1);
	return (0);
}

// int	main(void)
// {
// 	initStack(&stack);

// 	/* ゴールの位置を設定 */
// 	maze[5][3] = GOAL;

// 	/* スタート位置を(1,3)として開始 */
// 	if (ft_search(1, 3)) {
// 		printf("ゴールが見つかりました！\n");
// 	} else {
// 		printf("ゴールが見つかりません！\n");
// 	}

// 	return 0;
// }
