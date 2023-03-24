/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:49:40 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/23 18:55:56 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * マップデータの行数を取得
 * 
 * @param	ファイルディスクリプタ
 * @param	ファイル名
 * @return	行数
 */
static size_t	ft_line_len(int a_fd, char *a_file_name)
{
	ssize_t	r_size;
	size_t	r_return_num;
	char	r_buf[1];

	r_return_num = 1;
	while (1)
	{
		r_size = read(a_fd, r_buf, 1);
		if (r_size == -1)
			return (0);
		if (r_size == 0)
			return (r_return_num);
		if (r_buf[0] == '\n')
			r_return_num++;
	}
}

/*
 * マップデータを2次元配列へ格納する
 * 
 * @param	コマンドライン引数の値
 * @return	マップデータを2次元配列へ格納した値
 */
char	**ft_map_str(char **a_argv)
{
	int		r_fd;
	size_t	r_line_len;
	char	**r_return_str;
	size_t	i;

	r_fd = open(a_argv[1], O_RDONLY);
	if (r_fd == -1)
		return (NULL);
	r_line_len = ft_line_len(r_fd, a_argv[1]);
	if (r_line_len == 0)
		return (NULL);
	r_return_str = (char **)ft_calloc((r_line_len + 1), sizeof(char *));
	if (r_return_str == NULL)
		return (NULL);
	i = 0;
	while (i < r_line_len)
	{
		r_return_str[i] = get_next_line(r_fd);
		i++;
	}
	r_return_str[i] = NULL;
	close(r_fd);
	return (r_return_str);
}
