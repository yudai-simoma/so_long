/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eroor_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:45:54 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/23 20:22:51 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * エラー処理の種類
 *  ・地図はこの5文字だけで構成することができます：
 *  ・マップには、1つの出口、少なくとも1つの収集品、1つのスタート地点が含まれていなければなりません。
 *  ・マップは長方形である必要があります。
 *  ・地図が閉じている／壁で囲まれている必要がある。
 *  ・マップに有効なパスがあるかどうかをチェックする必要がある。
 *  ・マップデータが.berでなければならない
 *  ・
 */

int	ft_error_check(int argc, char **argv, t_vars *r_vars)
{
	argc = 0;
	argv = NULL;
	//添字番号指定
	r_vars->start_x = 3;
	r_vars->start_y = 1;
	r_vars->item_num = 1;
	return (0);
}
