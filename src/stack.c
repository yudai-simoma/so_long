/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:44:49 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/25 21:58:08 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdbool.h>

/*
 * スタックを初期化する
 * 最後尾を-1にすることで、空とする
 */
void	ft_init_stack(t_stack *a_stack)
{
	a_stack->tail = -1;
}

/*
 * スタックに値を追加する
 *   スタックが満杯なら何もせず関数終了
 */
void	ft_push(t_stack *a_stack, t_cell *a_input)
{
	if (a_stack->tail >= a_stack->max_num - 1)
	{
		ft_printf("Cannot PUSH because the stack is full\n");
		return ;
	}
	a_stack->tail++;
	a_stack->data[a_stack->tail] = *a_input;
}

/*
 * スタックから値を取り出す
 *   スタックが空なら何もせず関数終了
 */
t_cell	*ft_pop(t_stack *a_stack)
{
	t_cell	*r_return_cell;

	if (a_stack->tail == -1)
	{
		ft_printf("Cannot POP because the stack is empty\n");
		return (NULL);
	}
	r_return_cell = &(a_stack->data[a_stack->tail]);
	a_stack->tail--;
	return (r_return_cell);
}

bool	ft_is_empty(t_stack *a_stack)
{
	if (a_stack->tail == -1)
		return (true);
	return (false);
}

void ft_print_stack(t_stack *a_stack)
{
	for (int i = 0; i <= a_stack->tail; i++)
	{
		ft_printf("(x : %d, y : %d)", a_stack->data[i].y, a_stack->data[i].x);
	}
	ft_printf("\n");
}
