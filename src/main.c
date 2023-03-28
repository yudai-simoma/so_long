/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:25:50 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/28 17:37:29 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_str(char **str)
{
	size_t	i;

	i = 0;
	while (str[i] != NULL)
	{
		ft_printf("free : %p\n", str[i]);
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
void	ft_set_img(t_data *a_img, void *a_mlx)
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

void	ft_map_len(t_map *r_map)
{
	size_t	i;

	i = 0;
	while (r_map->map_str[i] != NULL)
		i++;
	r_map->column = i;
	r_map->record = ft_strlen(r_map->map_str[0]) - 1;
}

void	ft_init_map(t_map *a_map)
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
		ft_printf("Error\n");
		ft_free_str(r_map.map_str);
		return (0);
	}
	ft_printf("not error hook\n");
	ft_free_str(r_map.map_str);
	r_map.map_str = NULL;
	r_map.map_str = ft_map_str(a_argv);
	if (r_map.map_str == NULL)
		return (0);
	// for (int i = 0; i < 6; i++) {
	// 	ft_printf("map_str[%d] = %s", i, r_map.map_str[i]);
	// }
	r_map.mlx = mlx_init();
	// ft_printf("\ncolumn = %z, record = %z\n", r_map.column, r_map.record);
	r_map.win = mlx_new_window(r_map.mlx, 50 * r_map.record,
			50 * r_map.column, "Hello world!");
	ft_set_img(r_map.img_data, r_map.mlx);
	mlx_loop_hook(r_map.mlx, ft_map_put_img, &r_map);
	mlx_loop(r_map.mlx);
	// ft_free_str(r_map.map_str);
	return (0);
}

#include <libc.h>

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}