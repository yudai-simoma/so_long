/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eroor_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:45:54 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/21 20:52:10 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error_check(int argc, char **argv, t_vars *r_vars)
{
	argc = 0;
	argv = NULL;
	//添字番号指定
	r_vars->start_x = 3;
	r_vars->start_y = 1;
	return (0);
}
