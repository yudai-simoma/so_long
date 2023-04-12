/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:25:50 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/05 19:14:35 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * マップデータの2次元配列の動的メモリを解放する
 */
void	ft_free_str(char **str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

/*
 * 画像データを使用可能な変数へ格納する
 * 
 * @param	画像データ構造体
 * @param	void *a_mlx
 * @return	なし
 */
static void	ft_set_img(t_data *a_img, void *a_mlx)
{
	int		img_width;
	int		img_height;

	a_img[0].img = mlx_xpm_file_to_image(a_mlx,
			"./img/heaven.xpm", &img_width, &img_height);
	a_img[1].img = mlx_xpm_file_to_image(a_mlx,
			"./img/snake.xpm", &img_width, &img_height);
	a_img[2].img = mlx_xpm_file_to_image(a_mlx,
			"./img/apple.xpm", &img_width, &img_height);
	a_img[3].img = mlx_xpm_file_to_image(a_mlx,
			"./img/hell.xpm", &img_width, &img_height);
	a_img[4].img = mlx_xpm_file_to_image(a_mlx,
			"./img/girl.xpm", &img_width, &img_height);
}

/*
 * マップの列の数と行の数を取得する
 * 列は最大列数としている
 */
void	ft_max_map_len(t_map *a_map)
{
	size_t	i;
	size_t	j;
	size_t	max_record;
	size_t	column_flg;

	i = 0;
	max_record = 0;
	column_flg = 1;
	while (a_map->map_str[i] != NULL)
	{
		j = 0;
		while (a_map->map_str[i][j] != '\0')
			j++;
		if (a_map->map_str[i][j - 1] != '\n')
		{
			j++;
			column_flg = 0;
		}
		if (j > max_record)
			max_record = j;
		i++;
	}
	a_map->column = i + column_flg;
	a_map->record = max_record - 1;
}

/*
 * t_mapの構造体を初期化する
 */
static void	ft_init_map(t_map *a_map)
{
	int	i;

	a_map->move_count = 0;
	a_map->mlx = NULL;
	a_map->win = NULL;
	i = 0;
	while (i < 5)
	{
		a_map->img_data[i].img = NULL;
		i++;
	}
	a_map->map_str = NULL;
	a_map->start_x = 0;
	a_map->start_y = 0;
	a_map->end_x = 0;
	a_map->end_y = 0;
	a_map->column = 0;
	a_map->record = 0;
	a_map->item_num = 0;
	a_map->move_count = 0;
}

int	main(int a_argc, char **a_argv)
{
	t_map	r_map;

	ft_init_map(&r_map);
	if (ft_error_check(a_argc, a_argv, &r_map))
	{
		ft_printf("Error\nMap data is incorrect.\n");
		ft_free_str(r_map.map_str);
		return (0);
	}
	ft_free_str(r_map.map_str);
	r_map.map_str = NULL;
	r_map.map_str = ft_map_str(a_argv);
	if (r_map.map_str == NULL)
		return (0);
	r_map.mlx = mlx_init();
	r_map.win = mlx_new_window(r_map.mlx, 50 * r_map.record,
			50 * r_map.column, "go to hell");
	ft_set_img(r_map.img_data, r_map.mlx);
	mlx_loop_hook(r_map.mlx, ft_map_put_img, &r_map);
	mlx_loop(r_map.mlx);
	return (0);
}

// #include <libc.h>

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q so_long");
// }