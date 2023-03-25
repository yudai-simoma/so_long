/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:25:50 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/25 20:23:25 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	a_img[0].img = mlx_png_file_to_image(a_mlx,
			"./img/base.png", &img_width, &img_height);
	a_img[1].img = mlx_png_file_to_image(a_mlx,
			"./img/light.png", &img_width, &img_height);
	a_img[2].img = mlx_png_file_to_image(a_mlx,
			"./img/light.png", &img_width, &img_height);
	a_img[3].img = mlx_png_file_to_image(a_mlx,
			"./img/light.png", &img_width, &img_height);
	a_img[4].img = mlx_png_file_to_image(a_mlx,
			"./img/light.png", &img_width, &img_height);
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
	a_map->column = 0;
	a_map->record = 0;
	a_map->item_num = 0;
	a_map->move_count = 0;
}

int	main(int argc, char **argv)
{
	t_map	r_map;

	ft_init_map(&r_map);
	if (ft_error_check(argc, argv, &r_map))
	{
		ft_printf("Error\n");
		free(r_map.map_str);
		return (0);
	}
	for (int i = 0; i < 6; i++) {
		ft_printf("map_str[%d] = %s", i, r_map.map_str[i]);
	}
	r_map.mlx = mlx_init();
	ft_printf("\ncolumn = %z, record = %z\n", r_map.column, r_map.record);
	r_map.win = mlx_new_window(r_map.mlx, 64 * r_map.record,
			64 * r_map.column, "Hello world!");
	ft_set_img(r_map.img_data, r_map.mlx);
	mlx_loop_hook(r_map.mlx, ft_map_put_img, &r_map);
	mlx_loop(r_map.mlx);
	// free (r_map.data->img);
	return (0);
}
