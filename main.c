#include "mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 900, 900, "Hello world!");
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x0000FF00);
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (i % 2 == 0)
				mlx_pixel_put(mlx, mlx_win, i, j, 0x0000FF00);
		}
	}
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
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
