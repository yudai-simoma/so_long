/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:12:35 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/23 20:28:40 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h> //open関数
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line_bonus.h"
# include "../minilibx_mms_20200219/mlx.h"

# define MLX_SYNC_IMAGE_WRITABLE	1
# define MLX_SYNC_WIN_FLUSH_CMD		2
# define MLX_SYNC_WIN_CMD_COMPLETED	3

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef enum e_event {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
}	t_event;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_data	data[5];
	char	**map_str;
	size_t	start_x;
	size_t	start_y;
	size_t	column;
	size_t	record;
	ssize_t	item_num;
	size_t	move_count;
}	t_vars;

//error_check
int				ft_error_check(int argc, char **argv, t_vars *r_vars);

//map_str
char			**ft_map_str(char **argv);

//map_put_img
void			ft_set_img(t_data *a_img, void *a_mlx);
int				ft_put_img(void *a_vars);

//kye_hook
int				ft_key_hook(int r_keycode, void *r_vars);
// int				ft_key_hook(int r_keycode, t_vars *r_vars);

//utils
// size_t			ft_arr_size_pp(char **a_str);
void			ft_map_len(t_vars *r_vars);
int				ft_mouse_hook(int r_keycode, void *a_vars);

#endif