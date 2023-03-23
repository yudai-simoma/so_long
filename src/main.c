/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:25:50 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/22 19:19:42 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars	r_vars;
	// t_data	r_img[5];
	// char	**r_map_str;

	r_vars.move_count = 0;
	if (ft_error_check(argc, argv, &r_vars))
		return (0);
	r_vars.map_str = ft_map_str(argv);
	if (r_vars.map_str == NULL)
		return (0);
	for (int i = 0; i < 5; i++) {
		ft_printf("map_str[%d] = %s", i, r_vars.map_str[i]);
	}
	ft_map_len(&r_vars);//マップの行数、列数を取得
	r_vars.mlx = mlx_init();
	r_vars.win = mlx_new_window(r_vars.mlx, 1000, 500, "Hello world!");
	// r_vars.data = (t_data *)ft_calloc(5, sizeof(t_data *));
	ft_set_img(r_vars.data, r_vars.mlx);//画像の読み込み
	mlx_loop_hook(r_vars.mlx, ft_put_img, &r_vars);
	mlx_loop(r_vars.mlx);
	// free (r_vars.data->img);
	return (0);
}

//  int main()
//  {
//      void *mlx;//スクリーン接続識別子
//      void *mlx_win;//ウィンドウ識別子
//      int i;
//      int j;
//      int width = 1000; //ウィンドウのサイズ
//      int height = 1000;
 
//      mlx = mlx_init();//mlxの機能を使う前に一度呼び出す必要がある
//      mlx_win = mlx_new_window(mlx, width, height,"test");
// 		// mlx_win = mlx_new_window(スクリーン識別子, width, height,"test");
// 		//座標は左上が原点、矢印はx軸が右、y軸が下向きになる
// 		//でも与えられる図形の座標は一般的な向きの座標のためあとで座標変換が必要となる
//     	i= 0;
// 		while (i < width)
// 		{
// 				j = 0;
// 				while (j < height)
// 				{
// 						mlx_pixel_put(mlx, mlx_win, i, j, 127);
// 						j++;
// 				}
// 				i++;
// 		}
//      mlx_loop(mlx);//無限ループを作り、その間ウィンドウを表示させ続ける
//      //最初のうちはcntl+Cで強制終了すればおk
//      //クリックした時に終了させるなどのプログラムはゆくゆく書く必要がある
//      return (1);
//  }
