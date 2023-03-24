/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_put_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:18:58 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/24 19:46:36 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
static int	ft_key_hook(int r_keycode, void *a_vars)
{
	t_map	*r_vars;

	r_vars = (t_map *)a_vars;
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

static int	ft_mouse_hook(int r_keycode, void *a_vars)
{
	exit(0);
	return (0);
}

/*
 * 2次元配列の文字列を確認し、その値によって画像を表示する
 * 
 * @param	マップデータの構造体
 * @param	横の位置
 * @param	縦の位置
 * @return	無し
 * 
 * ON_KEYDOWN = キーボード押下
 * ON_DESTROY = ×ボタンをクリック
 */
static void	ft_map_put_img_sub(t_map *a_vars, size_t i, size_t j)
{
	if (a_vars->map_str[i][j] == '1')
		mlx_put_image_to_window(a_vars->mlx, a_vars->win,
			a_vars->img_data[1].img, j * 64, i * 64);
	else if (a_vars->map_str[i][j] == 'C')
		mlx_put_image_to_window(a_vars->mlx,
			a_vars->win, a_vars->img_data[2].img, j * 64, i * 64);
	else if (a_vars->map_str[i][j] == 'E')
		mlx_put_image_to_window(a_vars->mlx,
			a_vars->win, a_vars->img_data[3].img, j * 64, i * 64);
	else if (a_vars->map_str[i][j] == 'P')
		mlx_put_image_to_window(a_vars->mlx,
			a_vars->win, a_vars->img_data[4].img, j * 64, i * 64);
}

/*
 * 画像データをマップに描画する
 * 
 * @param	マップデータの構造体
 * @return	int
 * 
 * ON_KEYDOWN = キーボード押下
 * ON_DESTROY = ×ボタンをクリック
 */
int	ft_map_put_img(void *a_vars)
{
	t_map	*r_vars;
	size_t	i;
	size_t	j;

	r_vars = (t_map *)a_vars;
	mlx_hook(r_vars->win, ON_KEYDOWN, 1L << 0, ft_key_hook, (void *)r_vars);
	mlx_hook(r_vars->win, ON_DESTROY, 1L << 0, ft_mouse_hook, (void *)r_vars);
	mlx_put_image_to_window(r_vars->mlx,
		r_vars->win, r_vars->img_data[0].img, 0, 0);
	i = 0;
	while (i < r_vars->column)
	{
		j = 0;
		while (j < r_vars->record)
		{
			ft_map_put_img_sub(r_vars, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
