/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:25:50 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/20 14:43:13 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	ft_win_close(int keycode, t_vars *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->mlx_win);
	return (0);
}

int	ft_key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_data	img[4];
	int		img_width;
	int		img_height;
	int		x;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 2000, 900, "Hello world!");
	img[0].img = mlx_png_file_to_image(vars.mlx, "./img/base.png", &img_width, &img_height);
	img[1].img = mlx_png_file_to_image(vars.mlx, "./img/light.png", &img_width, &img_height);
	img[2].img = mlx_png_file_to_image(vars.mlx, "./img/light.png", &img_width, &img_height);
	img[3].img = mlx_png_file_to_image(vars.mlx, "./img/light.png", &img_width, &img_height);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img[0].img, 0, 0);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img[1].img, 200, 200);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img[2].img, 250, 250);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img[3].img, 300, 300);
	// for (int i = 10; i < 110; i++) {
	// 	for (int j = 10; j < 110; j++) {
	// 		if (i % 2 == 0)
	// 			mlx_pixel_put(vars.mlx, vars.mlx_win, i, j, ft_create_trgb(40, j, i, j));
	// 	}
	// }
	//ON_KEYDOWN指定のため, キーボードが押されたらft_win_closeが呼ばれる
	mlx_hook(vars.mlx_win, ON_KEYDOWN, 1L<<0, ft_win_close, &vars);
	//キーボードが押されたらft_key_hookが呼ばれる
	mlx_key_hook(vars.mlx_win, ft_key_hook, &vars);
	mlx_loop(vars.mlx);
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
