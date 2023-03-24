/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:39:26 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/24 20:39:39 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dfs.h"

/*
 * キューを初期化する
 * 先頭を0、最後尾を-1にすることで、空とする
 */
void ft_initQueue(t_queue *a_queue)
{
    a_queue->head = 0;
    a_queue->tail = -1;
}

/*
 * キューに値を追加する
 *   キューが満杯なら何もせず関数終了
 *   データをデータの最後尾の１つ後ろに格納
 *   データの最後尾を１つ後ろに移動
 * 「head の１つ後ろにはデータを追加しない」制約を設けるため、2つ後ろの位置にheadがあれば満杯とする
 */
void ft_enqueue(t_queue *a_queue, int a_input)
{
    if((a_queue->tail + 2) % MAX_NUM == a_queue->head){
        printf("Cannot ENQUEUE because the queue is full\n");
        return;
    }
    a_queue->data[(a_queue->tail + 1) % MAX_NUM] = a_input;
    a_queue->tail = (a_queue->tail + 1) % MAX_NUM;
}

/*
 * キューから値を取り出す
 *   キューが空なら何もせず関数終了
 *   データの先頭からデータを取得
 *   データの先頭を１つ後ろにずらす
 *   取得したデータを返却
 */
int ft_dequeue(t_queue *a_queue)
{
    int r_return_num;

    if((a_queue->tail + 1) % MAX_NUM == a_queue->head){
        printf("Cannot DEQUEUE because the queue is empty\n");
        return (0);
    }
    r_return_num = a_queue->data[a_queue->head];
    a_queue->head = (a_queue->head + 1) % MAX_NUM;
    return r_return_num;
}

/*
 * キューの中身を表示する
 *   キュー内のデータの個数を計算
 *   データの先頭からnum個分のデータを表示
 */
void ft_printQueue(t_queue *a_queue)
{
    int i;
    int r_num;

    if (a_queue->tail < a_queue->head) {
        if (a_queue->tail == (a_queue->head - 1))
            r_num = 0;
        else
            r_num = a_queue->tail + MAX_NUM - a_queue->head + 1;
    } else {
        r_num = a_queue->tail - a_queue->head + 1;
    }
    i = 0;
    while (i < r_num)
    {
        printf("%d,", a_queue->data[(a_queue->head + i) % MAX_NUM]);
        i++;
    }
    printf("\n");
}

int main(void){

    int     r_output;
    t_queue r_queue;
    
    /* キューを初期化 */
    ft_initQueue(&r_queue);
    ft_printQueue(&r_queue);
    printf("%dをENQUEUEします\n", 2);
    ft_enqueue(&r_queue, 2);
    r_output = ft_dequeue(&r_queue);
    printf("%dをDEQUEUEしました\n", r_output);
    ft_enqueue(&r_queue, 3);
    ft_enqueue(&r_queue, 4);
    ft_enqueue(&r_queue, 5);
    ft_enqueue(&r_queue, 6);
    ft_enqueue(&r_queue, 7);
    ft_printQueue(&r_queue);
    return 0;
}