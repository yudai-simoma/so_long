/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:45:54 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/05 19:12:39 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * エラー処理の種類
 *  ・マップデータの拡張子が「.ber」でなければならない
 *  ・地図は5文字「1, 0, P, C, E」だけで構成されていなければならない
 *  ・マップには、1つの出口、少なくとも1つの収集品、1つのスタート地点が含まれていなければならない
 *  ・マップは長方形でなければならない
 *  ・地図が壁で囲まれていなければならない
 *  ・マップに有効なパスがあるかどうかをチェックし、有効なマップで無ければならない
 */

/*
 * ・マップが壁(1)で囲まれているか確認
 */
static int	ft_enclose_check(t_map *a_map)
{
	size_t	i;

	i = 0;
	while ((a_map->map_str[0][i] != '\0')
		&& (a_map->map_str[a_map->column - 1] != NULL)
		&& (i < a_map->record)
		&& (a_map->map_str[0][i] == '1'
		&& a_map->map_str[a_map->column - 1][i] == '1'))
	{
		i++;
	}
	if (i != a_map->record)
		return (1);
	i = 0;
	while ((i < a_map->column) && a_map->map_str[i] != NULL)
	{
		if (a_map->map_str[i][0] != '1' ||
			a_map->map_str[i][a_map->record -1] != '1')
			return (1);
		i++;
	}
	return (0);
}

/*
 * スタート地点とゴール地点の座標を取得する
 */
static void	ft_set_xy(t_map *a_map, size_t i, size_t j, char c)
{
	if (c == 'p')
	{
		a_map->start_x = i;
		a_map->start_y = j;
	}
	else if (c == 'e')
	{
		a_map->end_x = i;
		a_map->end_y = j;
	}
}

/*
 * マップデータの中から、出口、収集品、スタート地点の数を取得する
 */
static void	ft_char_set(t_error *a_error, t_map *a_map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < a_map->column)
	{
		j = 0;
		while (j < a_map->record)
		{
			if (a_map->map_str[i][j] == 'C')
				a_error->c_num++;
			else if (a_map->map_str[i][j] == 'P')
			{
				ft_set_xy(a_map, i, j, 'p');
				a_error->p_num++;
			}
			else if (a_map->map_str[i][j] == 'E')
			{
				ft_set_xy(a_map, i, j, 'e');
				a_error->e_num++;
			}
			j++;
		}
		i++;
	}
}

/*
 * マップの文字種類チェック、該当の5文字のみか確認
 * マップは、1つの出口、少なくとも1つの収集品、1つのスタート地点であるか確認
 */
static int	ft_char_check(t_error *a_error, t_map *a_map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < a_map->column)
	{
		j = 0;
		while (j < a_map->record)
		{
			if (ft_strchr("01CEP", a_map->map_str[i][j]) == NULL)
				return (1);
			j++;
		}
		i++;
	}
	a_error->c_num = 0;
	a_error->p_num = 0;
	a_error->e_num = 0;
	ft_char_set(a_error, a_map);
	if (a_error->c_num < 1 || a_error->p_num != 1 || a_error->e_num != 1)
		return (1);
	return (0);
}

/*
 * エラーチェックで最初に呼ばれる関数（mainから呼ばれる）
 * 戻り値の1がエラー、0が正常
 */
int	ft_error_check(int a_argc, char **a_argv, t_map *a_map)
{
	t_error	r_error;

	if (a_argc != 2)
		return (1);
	r_error.name_len = ft_strlen(a_argv[1]);
	if (ft_file_check(a_argv[1], &r_error))
		return (1);
	a_map->map_str = ft_map_str(a_argv);
	if (a_map->map_str == NULL || a_map->map_str[0] == NULL)
		return (1);
	ft_max_map_len(a_map);
	if (ft_size_check(a_map))
		return (1);
	if (ft_enclose_check(a_map))
		return (1);
	if (ft_char_check(&r_error, a_map))
		return (1);
	if (ft_map_path_check(a_map, &r_error))
		return (1);
	a_map->item_num = r_error.c_num;
	return (0);
}
