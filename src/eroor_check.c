/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eroor_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:45:54 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/24 20:34:30 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * エラー処理の種類
 *  済マップデータが.berでなければならない
 *  済地図はこの5文字だけで構成することができます：
 *  済マップには、1つの出口、少なくとも1つの収集品、1つのスタート地点が含まれていなければなりません。
 *  済マップは長方形である必要があります。
 *  済地図が壁で囲まれている必要がある。
 *  ・マップに有効なパスがあるかどうかをチェックする必要がある。
 *  ・
 */

/*
 * ・地図が壁で囲まれている必要がある。
 */
int	ft_enclose_check(t_error *a_error, t_map *a_map)
{
	size_t	i;

	i = 0;
	while (a_map->map_str[0][i] == '1'
		&& a_map->map_str[a_map->column][i] == '1')
		i++;
	if (i != a_map->record)
		return (0);
	i = 0;
	while (a_map->map_str[i] == NULL)
	{
		if (a_map->map_str[0] != '1' && a_map->map_str[a_map->record -1] != '1')
			return (0);
		i++;
	}
	return (1);
}

/*
 *  ・地図はこの5文字だけで構成することができます：
 *  ・マップには、1つの出口、少なくとも1つの収集品、1つのスタート地点が含まれていなければなりません。
 * 
 */
void	ft_char_check(t_error *a_error, t_map *a_map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < a_map->column)
	{
		j = 0;
		while (j < a_map->record)
		{
			if (ft_strchr(a_error->check_str, a_map->map_str[i][j]) == NULL)
				return (1);
			else if (a_map->map_str[i][j] == 'C')
				a_error->c_num++;
			else if (a_map->map_str[i][j] == 'P')
			{
				a_map->start_x = i;
				a_map->start_y = j;
				a_error->p_num++;
			}
			else if (a_map->map_str[i][j] == 'E')
				a_error->e_num++;
			j++;
		}
		i++;
	}
}

int	ft_map_path_check(t_map *a_map)
{

}

/*
 * 1がエラー、0が正常
 */
int	ft_error_check(int a_argc, char **a_argv, t_map *a_map)
{
	t_error	r_error;

	if (a_argc != 2)
		return (1);
	r_error.name_len = ft_strlen(a_argv[1]);
	if (!a_argv[1][r_error.name_len - 4] == '.'
		&& a_argv[1][r_error.name_len - 3] == 'b'
		&& a_argv[1][r_error.name_len - 2] == 'e'
		&& a_argv[1][r_error.name_len - 1] == 'r')
		return (1);
	r_error.c_num = 0;
	r_error.p_num = 0;
	r_error.e_num = 0;
	ft_char_check(&r_error, a_map);
	if (!r_error.c_num >= 1 && r_error.p_num == 1 && r_error.e_num == 1)
		return (1);
	if ((a_map->column == a_map->record)
		&& (a_map->column >= 3 && a_map->record >= 3))
		return (1);
	if (!ft_enclose_check(&r_error, a_map))
		return (1);
	if (!ft_map_path_check(a_map))
		return (1);
	a_map->item_num = &r_error.c_num;
	return (0);
}
