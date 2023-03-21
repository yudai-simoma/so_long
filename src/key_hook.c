/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:47:50 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/21 11:48:07 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook(int keycode, t_vars *vars)
{
	ft_printf("Hello from key_hook!\n");
	if (keycode == 53)
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}
