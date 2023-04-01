/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:12:35 by yshimoma          #+#    #+#             */
/*   Updated: 2023/04/01 14:06:43 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h> //open, close関数
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line_bonus.h"
# include "../minilibx_mms_20200219/mlx.h"

# define ON_KEYDOWN	2
# define ON_DESTROY	17

/*
 * 画像データの構造体
 * 
 * img : 画像のデータ
 */
typedef struct s_data {
	void	*img;
}	t_data;

/*
 * マップデータの構造体
 * 
 * mlx : MLX インスタンス, win : 新しいウィンドウのインスタンス
 * img_date : 画像データの構造体, map_str : マップデータを格納する2次元配列
 * start_x : スタート位置の行情報, start_y : スタート位置の列情報
 * end_x : ゴール位置の行情報, end_y : ゴール位置の列情報
 * column : マップの行数, record : マップの列数
 * item_num : アイテムの個数（0になるとゴール可能）move_count : 移動した回数
 * 
 */
typedef struct s_map {
	void	*mlx;
	void	*win;
	t_data	img_data[5];
	char	**map_str;
	size_t	start_x;
	size_t	start_y;
	size_t	end_x;
	size_t	end_y;
	size_t	column;
	size_t	record;
	size_t	item_num;
	size_t	move_count;
}	t_map;

/*
 * エラー処理の構造体
 * 
 * img : 画像のデータ
 */
typedef struct s_error {
	size_t		name_len;
	size_t		c_num;
	size_t		p_num;
	size_t		e_num;
}	t_error;

//マスの情報
typedef struct s_cell {
	int	x;
	int	y;
}	t_cell;

//スタック構造体s
typedef struct s_stack {
	int		tail;
	t_cell	*data;
	int		max_num;
	size_t	c_num;
	size_t	e_num;
}	t_stack;

//main.c
void	ft_free_str(char **str);
void	ft_max_map_len(t_map *a_vars);
int		main(int a_argc, char **a_argv);
//error_check.c
int		ft_error_check(int a_argc, char **a_argv, t_map *a_map);
//error_check_utils.c
int		ft_file_check(char *a_name, t_error	*a_error);
int		ft_size_check(t_map *a_map);
//map_str.c
char	**ft_map_str(char **argv);
//map_put_img.c
int		ft_map_put_img(void *a_vars);
//key_hook.c
void	ft_move_up(t_map *r_vars);
void	ft_move_right(t_map *r_vars);
void	ft_move_down(t_map *r_vars);
void	ft_move_left(t_map *r_vars);
//dfs.c
int		ft_map_path_check(t_map *a_map, t_error *a_error);
//stack.c
void	ft_init_stack(t_stack *a_stack);
void	ft_push(t_stack *a_stack, t_cell *a_input);
t_cell	*ft_pop(t_stack *a_stack);
// void	ft_print_stack(t_stack *a_stack);

#endif