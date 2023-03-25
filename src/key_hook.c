/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:47:50 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/25 14:24:08 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * スタート位置を移動させられるか判断する関数
 * 
 * @param	マップデータの構造体
 * @param	移動するマスの行情報
 * @param	移動するマスの列情報
 * @return	移動できる場合は1、できない場合は0もしくは強制終了
 * 
 * 上に移動できるかはft_move_check関数を呼び確認している
 */
int	ft_move_check(t_map *r_map, size_t x, size_t y)
{
	if ((r_map->map_str[x][y] == '1')
		|| (r_map->map_str[x][y] == 'E' && r_map->item_num != 0))
		return (0);
	else if (r_map->map_str[x][y] == 'C')
		r_map->item_num--;
	else if (r_map->map_str[x][y] == 'E' && r_map->item_num == 0)
	{
		mlx_destroy_window(r_map->mlx, r_map->win);
		exit(0);
	}
	return (1);
}

/*
 * スタート位置を上に移動させる処理
 * 
 * @param	マップデータの構造体
 * @return	なし
 * 
 * 上に移動できるかはft_move_check関数を呼び確認している
 */
void	ft_move_up(t_map *r_map)
{
	if (!ft_move_check(r_map, r_map->start_x - 1, r_map->start_y))
		return ;
	r_map->map_str[r_map->start_x][r_map->start_y] = '0';
	r_map->start_x--;
	r_map->map_str[r_map->start_x][r_map->start_y] = 'P';
	ft_printf("Number of moves %z\n", ++r_map->move_count);
}

/*
 * スタート位置を右に移動させる処理
 * 
 * @param	マップデータの構造体
 * @return	なし
 * 
 * 右に移動できるかはft_move_check関数を呼び確認している
 */
void	ft_move_right(t_map *r_map)
{
	if (!ft_move_check(r_map, r_map->start_x, r_map->start_y + 1))
		return ;
	r_map->map_str[r_map->start_x][r_map->start_y] = '0';
	r_map->start_y++;
	r_map->map_str[r_map->start_x][r_map->start_y] = 'P';
	ft_printf("Number of moves %z\n", ++r_map->move_count);
}

/*
 * スタート位置を下に移動させる処理
 * 
 * @param	マップデータの構造体
 * @return	なし
 * 
 * 下に移動できるかはft_move_check関数を呼び確認している
 */
void	ft_move_down(t_map *r_map)
{
	if (!ft_move_check(r_map, r_map->start_x + 1, r_map->start_y))
		return ;
	r_map->map_str[r_map->start_x][r_map->start_y] = '0';
	r_map->start_x++;
	r_map->map_str[r_map->start_x][r_map->start_y] = 'P';
	ft_printf("Number of moves %z\n", ++r_map->move_count);
}

/*
 * スタート位置を左に移動させる処理
 * 
 * @param	マップデータの構造体
 * @return	なし
 * 
 * 左に移動できるかはft_move_check関数を呼び確認している
 */
void	ft_move_left(t_map *r_map)
{
	if (!ft_move_check(r_map, r_map->start_x, r_map->start_y - 1))
		return ;
	r_map->map_str[r_map->start_x][r_map->start_y] = '0';
	r_map->start_y--;
	r_map->map_str[r_map->start_x][r_map->start_y] = 'P';
	ft_printf("Number of moves %z\n", ++r_map->move_count);
}
