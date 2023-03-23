/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:25:50 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/23 20:31:00 by yshimoma         ###   ########.fr       */
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
	for (int i = 0; i < 6; i++) {
		ft_printf("map_str[%d] = %s", i, r_vars.map_str[i]);
	}
	ft_map_len(&r_vars);//マップの行数、列数を取得
	r_vars.mlx = mlx_init();
	ft_printf("\ncolumn = %z, record = %z\n", r_vars.column, r_vars.record);
	r_vars.win = mlx_new_window(r_vars.mlx, 64 * r_vars.record, 64 * r_vars.column, "Hello world!");
	// r_vars.data = (t_data *)ft_calloc(5, sizeof(t_data *));
	ft_set_img(r_vars.data, r_vars.mlx);//画像の読み込み
	mlx_loop_hook(r_vars.mlx, ft_put_img, &r_vars);
	mlx_loop(r_vars.mlx);
	// free (r_vars.data->img);
	return (0);
}
