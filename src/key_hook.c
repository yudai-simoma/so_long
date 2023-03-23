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

static void	ft_move_up(t_vars *r_vars)
{
	if ((r_vars->map_str[r_vars->start_x - 1][r_vars->start_y] == '1')
		|| (r_vars->map_str[r_vars->start_x - 1][r_vars->start_y] == 'E'
			&& r_vars->item_num != 0))
		return ;
	else if (r_vars->map_str[r_vars->start_x - 1][r_vars->start_y] == 'C')
		r_vars->item_num--;
	else if (r_vars->map_str[r_vars->start_x - 1][r_vars->start_y] == 'E'
		&& r_vars->item_num == 0)
	{
		mlx_destroy_window(r_vars->mlx, r_vars->win);
		exit(0);
	}
	r_vars->map_str[r_vars->start_x][r_vars->start_y] = '0';
	r_vars->start_x--;
	r_vars->map_str[r_vars->start_x][r_vars->start_y] = 'P';
	ft_printf("Number of moves %z\n", ++r_vars->move_count);
}

static void	ft_move_right(t_vars *r_vars)
{
	if ((r_vars->map_str[r_vars->start_x][r_vars->start_y + 1] == '1')
		|| (r_vars->map_str[r_vars->start_x][r_vars->start_y + 1] == 'E'
			&& r_vars->item_num != 0))
		return ;
	else if (r_vars->map_str[r_vars->start_x][r_vars->start_y + 1] == 'C')
		r_vars->item_num--;
	else if (r_vars->map_str[r_vars->start_x][r_vars->start_y + 1] == 'E'
		&& r_vars->item_num == 0)
	{
		mlx_destroy_window(r_vars->mlx, r_vars->win);
		exit(0);
	}
	r_vars->map_str[r_vars->start_x][r_vars->start_y] = '0';
	r_vars->start_y++;
	r_vars->map_str[r_vars->start_x][r_vars->start_y] = 'P';
	ft_printf("Number of moves %z\n", ++r_vars->move_count);
}

static void	ft_move_down(t_vars *r_vars)
{
	if ((r_vars->map_str[r_vars->start_x + 1][r_vars->start_y] == '1')
		|| (r_vars->map_str[r_vars->start_x + 1][r_vars->start_y] == 'E'
			&& r_vars->item_num != 0))
		return ;
	else if (r_vars->map_str[r_vars->start_x + 1][r_vars->start_y] == 'C')
		r_vars->item_num--;
	else if (r_vars->map_str[r_vars->start_x + 1][r_vars->start_y] == 'E'
		&& r_vars->item_num == 0)
	{
		mlx_destroy_window(r_vars->mlx, r_vars->win);
		exit(0);
	}
	r_vars->map_str[r_vars->start_x][r_vars->start_y] = '0';
	r_vars->start_x++;
	r_vars->map_str[r_vars->start_x][r_vars->start_y] = 'P';
	ft_printf("Number of moves %z\n", ++r_vars->move_count);
}

static void	ft_move_left(t_vars *r_vars)
{
	if ((r_vars->map_str[r_vars->start_x][r_vars->start_y - 1] == '1')
		|| (r_vars->map_str[r_vars->start_x][r_vars->start_y - 1] == 'E'
			&& r_vars->item_num != 0))
		return ;
	else if (r_vars->map_str[r_vars->start_x][r_vars->start_y - 1] == 'C')
		r_vars->item_num--;
	else if (r_vars->map_str[r_vars->start_x][r_vars->start_y - 1] == 'E'
		&& r_vars->item_num == 0)
	{
		mlx_destroy_window(r_vars->mlx, r_vars->win);
		exit(0);
	}
	r_vars->map_str[r_vars->start_x][r_vars->start_y] = '0';
	r_vars->start_y--;
	r_vars->map_str[r_vars->start_x][r_vars->start_y] = 'P';
	ft_printf("Number of moves %z\n", ++r_vars->move_count);
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
