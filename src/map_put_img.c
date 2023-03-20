/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_put_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:18:58 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/20 20:45:22 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_wall(void *r_mlx, void *r_win, void *a_img, char **a_map_str)
{
	size_t	r_record;
	size_t	r_column;
	size_t	i;
	size_t	j;

	r_record = ft_strlen(a_map_str[0]);
	r_column = ft_arr_size_pp(a_map_str);
	i = 10;
	while (i < 10 + r_record)
	{
		j = 10;
		while (j < 10 + r_column)
		{
			// ft_printf("\ni = %d, j = %d", i, j);
			mlx_put_image_to_window(r_mlx, r_win, a_img, i * 10, j * 10);
			j++;
		}
		i++;
	}
}
