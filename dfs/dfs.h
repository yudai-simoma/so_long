/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:41:12 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/24 20:51:26 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DFS_H
# define DFS_H
# include <limits.h>
# include <stdio.h>

//以下のコメントはキューの仕様
//管理するデータの上限個数+1
//リングバッファの満杯、空の判断で+1を使用する
# define MAX_NUM INT_MAX

//スタック構造体
typedef struct s_stack {
	//データの最後尾
	int	tail;
	//スタックされているデータ
	int	data[MAX_NUM];
}	t_stack;

//キュー構造体
typedef struct s_queue {
	/* データの最後尾 */
	int	tail;
	/* データの先頭 */
	int	head;
	/* キューされているデータ */
	int	data[MAX_NUM];
}	t_queue;

//stack.c
void	ft_init_stack(t_stack *a_stack);
void	ft_push(t_stack *a_stack, int a_input);
int		ft_pop(t_stack *a_stack);
void	ft_print_stack(t_stack *a_stack);

//queue.c

#endif