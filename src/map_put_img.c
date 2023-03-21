/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_put_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:18:58 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/21 12:38:18 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_put_img_sub(t_vars *a_vars, size_t i, size_t j)
{
	if (a_vars->map_str[i][j] == '1')
		mlx_put_image_to_window(a_vars->mlx, a_vars->win,
			a_vars->data[1].img, j * 64, i * 64);
	else if (a_vars->map_str[i][j] == 'C')
		mlx_put_image_to_window(a_vars->mlx,
			a_vars->win, a_vars->data[2].img, j * 64, i * 64);
	else if (a_vars->map_str[i][j] == 'E')
		mlx_put_image_to_window(a_vars->mlx,
			a_vars->win, a_vars->data[3].img, j * 64, i * 64);
	else if (a_vars->map_str[i][j] == 'P')
		mlx_put_image_to_window(a_vars->mlx,
			a_vars->win, a_vars->data[4].img, j * 64, i * 64);
}

/*
 * 画像をマップに描画する
 */
// void	ft_put_img(void *a_mlx, void *a_win, t_data *a_img, char **a_map_str)
int	ft_put_img(void *a_vars)
{
	t_vars			*r_vars;
	const size_t	r_column = ft_arr_size_pp(r_vars->map_str);
	const size_t	r_record = ft_strlen(r_vars->map_str[0]) - 1;
	size_t			i;
	size_t			j;

	r_vars = (t_vars *)a_vars;
	i = 0;
	mlx_put_image_to_window(r_vars->mlx,
		r_vars->win, r_vars->data[0].img, 0, 0);
	while (i < r_column)
	{
		j = 0;
		while (j < r_record)
		{
			ft_put_img_sub(r_vars, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

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
