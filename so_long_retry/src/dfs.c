/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 12:15:54 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/01 15:09:23 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * 進めるマスかどうかの確認（壁もしくは一度進んだマスかの判断）
 */
static int	ft_move_sell_check(t_map *a_map, int x, int y)
{
	if (a_map->map_str[x][y] == '1')
		return (0);
	if (a_map->map_str[x][y] == '2')
		return (0);
	return (1);
}

/*
 * 進めるマスか確認しかつ、進めたマスがゴールやアイテムのマスなら個数をカウント
 * 一度進んだマスは'2'で埋める
 */
static int	ft_cell_move(t_map *a_map, t_stack *a_stack, int x, int y)
{
	t_cell	l_next;

	if (ft_move_sell_check(a_map, x, y))
	{
		l_next.x = x;
		l_next.y = y;
		if (a_map->map_str[x][y] == 'E')
			a_stack->e_num++;
		else if (a_map->map_str[x][y] == 'C')
			a_stack->c_num++;
		a_map->map_str[x][y] = '2';
		ft_push(a_stack, &l_next);
		return (1);
	}
	return (0);
}

/*
 * 上、下、右、左の順で進めるかチェックしながら確認していく
 */
static int	ft_search_sub(t_map *a_map, t_stack *a_stack, t_cell *a_next)
{
	int	l_return_flg;

	l_return_flg = 0;
	if (ft_cell_move(a_map, a_stack, a_next->x, a_next->y - 1))
	{
		a_next->y--;
		l_return_flg++;
	}
	else if (ft_cell_move(a_map, a_stack, a_next->x, a_next->y + 1))
	{
		a_next->y++;
		l_return_flg++;
	}
	else if (ft_cell_move(a_map, a_stack, a_next->x - 1, a_next->y))
	{
		a_next->x--;
		l_return_flg++;
	}
	else if (ft_cell_move(a_map, a_stack, a_next->x + 1, a_next->y))
	{
		a_next->x++;
		l_return_flg++;
	}
	return (l_return_flg);
}

/*
 * マップの通れる箇所を全探索する
 */
static void	ft_search(t_map *a_map, t_stack *a_stack)
{
	t_cell	*l_next;

	while (1)
	{
		l_next = ft_pop(a_stack);
		if (l_next == NULL)
			return ;
		ft_push(a_stack, l_next);
		if (!ft_search_sub(a_map, a_stack, l_next))
			l_next = ft_pop(a_stack);
	}
}

/*
 * マップに有効なパスがあるかどうかを確認する
 * マップを全探索し、「C, E」の個数を格納し以前に取得した個数と比較しエラーの判断をする
 */
int	ft_map_path_check(t_map *a_map, t_error *a_error)
{
	t_stack	l_stack;
	t_cell	l_start;

	ft_init_stack(&l_stack);
	if (a_map->column > INT_MAX / a_map->record)
		return (1);
	l_stack.max_num = a_map->column * a_map->record;
	l_stack.data = (t_cell *)malloc(sizeof(t_cell) * l_stack.max_num);
	if (l_stack.data == NULL)
		return (1);
	if (ft_move_sell_check(a_map, a_map->start_x, a_map->start_y))
	{
		l_start.x = a_map->start_x;
		l_start.y = a_map->start_y;
		ft_push(&l_stack, &l_start);
	}
	ft_search(a_map, &l_stack);
	free(l_stack.data);
	if (l_stack.e_num != 1 || l_stack.c_num != a_error->c_num)
		return (1);
	return (0);
}
