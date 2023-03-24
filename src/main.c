/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:25:50 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/24 19:54:28 by yshimoma         ###   ########.fr       */
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
static void	ft_set_img(t_data *a_img, void *a_mlx)
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

static void	ft_map_len(t_map *r_vars)
{
	size_t	i;

	i = 0;
	while (r_vars->map_str[i] != NULL)
		i++;
	r_vars->column = i;
	r_vars->record = ft_strlen(r_vars->map_str[0]) - 1;
}

int	main(int argc, char **argv)
{
	t_map	r_vars;

	//t_map構造体の初期化処理が必要かも
	r_vars.move_count = 0;
	r_vars.map_str = ft_map_str(argv);
	if (r_vars.map_str == NULL)
		return (0);
	ft_map_len(&r_vars);//マップの行数、列数を取得
	if (ft_error_check(argc, argv, &r_vars))
	{
		free(r_vars.map_str);
		return (0);
	}
	for (int i = 0; i < 6; i++) {
		ft_printf("map_str[%d] = %s", i, r_vars.map_str[i]);
	}
	r_vars.mlx = mlx_init();
	ft_printf("\ncolumn = %z, record = %z\n", r_vars.column, r_vars.record);
	r_vars.win = mlx_new_window(r_vars.mlx, 64 * r_vars.record, 64 * r_vars.column, "Hello world!");
	// r_vars.data = (t_data *)ft_calloc(5, sizeof(t_data *));
	ft_set_img(r_vars.img_data, r_vars.mlx);//画像の読み込み
	mlx_loop_hook(r_vars.mlx, ft_map_put_img, &r_vars);
	mlx_loop(r_vars.mlx);
	// free (r_vars.data->img);
	return (0);
}
