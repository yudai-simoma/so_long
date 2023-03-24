/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:44:49 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/24 21:07:39 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dfs.h"

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
void	ft_push(t_stack *a_stack, int a_input)
{
	if (a_stack->tail >= MAX_NUM - 1)
	{
		printf("Cannot PUSH because the stack is full\n");
		return ;
	}
	a_stack->tail++;
	a_stack->data[a_stack->tail] = a_input;
}

/*
 * スタックから値を取り出す
 *   スタックが空なら何もせず関数終了
 */
int	ft_pop(t_stack *a_stack)
{
	int	r_return_num;

	r_return_num = 0;
	if (a_stack->tail == -1)
	{
		printf("Cannot POP because the stack is empty\n");
		return (-1);
	}
	r_return_num = a_stack->data[a_stack->tail];
	a_stack->tail--;
	return (r_return_num);
}

/*
 * スタックの中身を表示する
 */
void	ft_print_stack(t_stack *a_stack)
{
	int	i;

	i = 0;
	while (i < a_stack->tail + 1)
	{
		printf("date[%d] = %d,", i, a_stack->data[a_stack->tail - i]);
		i++;
	}
	printf("\n");
}

int main(void){
	int output;
	t_stack stack;

	ft_init_stack(&stack);
	ft_print_stack(&stack);
	ft_push(&stack, 2);
	output = ft_pop(&stack);
	printf("%dをPOPしました\n", output);
	ft_push(&stack, 3);
	ft_print_stack(&stack);
	return 0;
}