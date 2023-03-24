/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:47:50 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/23 20:31:18 by yshimoma         ###   ########.fr       */
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
int	ft_move_check(t_vars *r_vars, size_t x, size_t y)
{
	if ((r_vars->map_str[x][y] == '1')
		|| (r_vars->map_str[x][y] == 'E' && r_vars->item_num != 0))
		return (0);
	else if (r_vars->map_str[x][y] == 'C')
		r_vars->item_num--;
	else if (r_vars->map_str[x][y] == 'E' && r_vars->item_num == 0)
	{
		mlx_destroy_window(r_vars->mlx, r_vars->win);
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
static void	ft_move_up(t_vars *r_vars)
{
	if (!ft_move_check(r_vars, r_vars->start_x - 1, r_vars->start_y))
		return ;
	r_vars->map_str[r_vars->start_x][r_vars->start_y] = '0';
	r_vars->start_x--;
	r_vars->map_str[r_vars->start_x][r_vars->start_y] = 'P';
	ft_printf("Number of moves %z\n", ++r_vars->move_count);
}

/*
 * スタート位置を右に移動させる処理
 * 
 * @param	マップデータの構造体
 * @return	なし
 * 
 * 右に移動できるかはft_move_check関数を呼び確認している
 */
static void	ft_move_right(t_vars *r_vars)
{
	if (!ft_move_check(r_vars, r_vars->start_x, r_vars->start_y + 1))
		return ;
	r_vars->map_str[r_vars->start_x][r_vars->start_y] = '0';
	r_vars->start_y++;
	r_vars->map_str[r_vars->start_x][r_vars->start_y] = 'P';
	ft_printf("Number of moves %z\n", ++r_vars->move_count);
}

/*
 * スタート位置を下に移動させる処理
 * 
 * @param	マップデータの構造体
 * @return	なし
 * 
 * 下に移動できるかはft_move_check関数を呼び確認している
 */
static void	ft_move_down(t_vars *r_vars)
{
	if (!ft_move_check(r_vars, r_vars->start_x + 1, r_vars->start_y))
		return ;
	r_vars->map_str[r_vars->start_x][r_vars->start_y] = '0';
	r_vars->start_x++;
	r_vars->map_str[r_vars->start_x][r_vars->start_y] = 'P';
	ft_printf("Number of moves %z\n", ++r_vars->move_count);
}

/*
 * スタート位置を左に移動させる処理
 * 
 * @param	マップデータの構造体
 * @return	なし
 * 
 * 左に移動できるかはft_move_check関数を呼び確認している
 */
static void	ft_move_left(t_vars *r_vars)
{
	if (!ft_move_check(r_vars, r_vars->start_x, r_vars->start_y - 1))
		return ;
	r_vars->map_str[r_vars->start_x][r_vars->start_y] = '0';
	r_vars->start_y--;
	r_vars->map_str[r_vars->start_x][r_vars->start_y] = 'P';
	ft_printf("Number of moves %z\n", ++r_vars->move_count);
}

/*
 * キーボード押下時に呼ばれ、押下されたボタンによって処理を行う
 * 
 * @param	押下されたキー種類（aなのかescなのか等）
 * @param	マップデータの構造体（void *で受け取るため、キャストする）
 * @return	int
 * 
 * ifで使用している数字のキー種類
 * 0 = A, 1 = S, 2 = D, 13 = W
 * 126 = ↑, 124 = →, 125 = ↓, 123 = ←
 */
int	ft_key_hook(int r_keycode, void *a_vars)
{
	t_vars	*r_vars;

	r_vars = (t_vars *)a_vars;
	if (r_keycode == 0 || r_keycode == 126)
		ft_move_up(r_vars);
	else if (r_keycode == 1 || r_keycode == 124)
		ft_move_right(r_vars);
	else if (r_keycode == 2 || r_keycode == 125)
		ft_move_down(r_vars);
	else if (r_keycode == 13 || r_keycode == 123)
		ft_move_left(r_vars);
	else if (r_keycode == 53)
	{
		mlx_destroy_window(r_vars->mlx, r_vars->win);
		exit (0);
	}
	return (0);
}
