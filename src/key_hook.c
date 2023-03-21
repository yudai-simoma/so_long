/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:47:50 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/21 21:09:56 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * TODO
 *  壁はすり抜けられない処理追加
 * 	アイテムを取得時のフラグチェック
 *  ゴール判定
 *  ゴール後のマップ終了
 */

static void	ft_move_up(t_vars *r_vars)
{
	r_vars->map_str[r_vars->start_x][r_vars->start_y] = '0';
	r_vars->start_x--;
	r_vars->map_str[r_vars->start_x][r_vars->start_y] = 'P';
}

static void	ft_move_right(t_vars *r_vars)
{
	r_vars->map_str[r_vars->start_x][r_vars->start_y] = '0';
	r_vars->start_y++;
	r_vars->map_str[r_vars->start_x][r_vars->start_y] = 'P';
}

static void	ft_move_down(t_vars *r_vars)
{
	r_vars->map_str[r_vars->start_x][r_vars->start_y] = '0';
	r_vars->start_x++;
	r_vars->map_str[r_vars->start_x][r_vars->start_y] = 'P';
}

static void	ft_move_left(t_vars *r_vars)
{
	r_vars->map_str[r_vars->start_x][r_vars->start_y] = '0';
	r_vars->start_y--;
	r_vars->map_str[r_vars->start_x][r_vars->start_y] = 'P';
}

/*
 * 
 * A = 0, S = 1, D = 2, W = 13
 * ↑ = 126, → = 124, ↓ = 125, ← = 123
 */
int	ft_key_hook(int r_keycode, void *a_vars)
{
	t_vars	*r_vars;

	r_vars = (t_vars *)a_vars;
	// ft_printf("keycode = %d, start_1 = %d, start_2 = %d\n", r_keycode, r_vars->start_p[0], r_vars->start_p[1]);
	if (r_keycode == 0 || r_keycode == 126)
		ft_move_up(r_vars);
	else if (r_keycode == 1 || r_keycode == 124)
		ft_move_right(r_vars);
	else if (r_keycode == 2 || r_keycode == 125)
		ft_move_down(r_vars);
	else if (r_keycode == 13 || r_keycode == 123)
		ft_move_left(r_vars);
	else if (r_keycode == 53)
		mlx_destroy_window(r_vars->mlx, r_vars->win);
	return (0);
}
