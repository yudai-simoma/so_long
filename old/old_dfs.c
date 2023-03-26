/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 10:40:02 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/26 12:12:10 by yshimoma         ###   ########.fr       */
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
	if (a_map->map_str[x][y] == '1')
		return (0);
	if (a_map->map_str[x][y] == '2')
		return (0);
	return (1);
}

#include <stdio.h>

/* スタート(i,j)からゴールを探索する関数*/
int	ft_search(t_map *a_map, t_stack	*a_stack, t_cell *a_cell)
{
	t_cell	*r_next;
	bool has_next;

	while (1)
	{
		printf("tail %d\n", a_stack->tail);
		ft_print_stack(a_stack);
		r_next = ft_pop(a_stack);
		if (r_next == NULL)
			return (0);
		ft_push(a_stack, r_next);
		if (a_map->map_str[r_next->x][r_next->y] == 'E')
			return (1);
		// a_map->map_str[r_next->x][r_next->y] = '2';
		has_next = false;
		if (ft_check_move_up(a_cell, a_stack, r_next, a_map))
			has_next = true;
		else if (ft_check_move_down(a_cell, a_stack, r_next, a_map))
			has_next = true;
		else if (ft_check_move_right(a_cell, a_stack, r_next, a_map))
			has_next = true;
		else if (ft_check_move_left(a_cell, a_stack, r_next, a_map))
			has_next = true;
		if (!has_next){
			ft_pop(a_stack);			
		}
	}
	return 0;
}

int	ft_map_path_check(t_map *a_map)
{
	t_stack	r_stack;
	t_cell	r_cell;

	if (a_map->column > INT_MAX / a_map->record)
		return (1);
	r_stack.max_num = a_map->column * a_map->record;
	r_stack.data = (t_cell *)malloc(sizeof(t_cell) * r_stack.max_num);
	ft_init_stack(&r_stack);
	/* 次の探索候補としてスタートのマスの情報をスタックに格納 */
	if (ft_check(a_map, a_map->start_x, a_map->start_y))
	{
		/* スタートのi座標*/
		r_cell.x = a_map->start_x;
		/* スタートのj座標*/
		r_cell.y = a_map->start_y;
		/* スタックにマスの情報を格納*/
		a_map->map_str[r_cell.x][r_cell.y] = '2';	
		ft_push(&r_stack, &r_cell);
	}
	ft_print_stack(&r_stack);
	if (ft_search(a_map, &r_stack, &r_cell))
	{
		for (int i = 0; i < 6; i++) {
			ft_printf("map_str[%d] = %s", i, a_map->map_str[i]);
		}
		printf("\n");
		printf("\n");
		free(r_stack.data);
		return (1);
	}
	free(r_stack.data);
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
