/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:12:04 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/19 12:26:02 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

/*
 * 
 * char[4] = {0 ,1, 2, 3}	
 * 
 * create_trgb(0, 1, 2, 3)の場合
 * (unsigned char [4]){b, g, r, t}) : char a[4] = [0][1][2][3]
 * int * : int* [0x00010203]
 * *(int *) : int 010203
 */
int	ft_create_trgb(unsigned char t, unsigned char r
	, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

/*
 * 
 * get_t(0x01020304)
 * ((unsigned char *)&trgb) : trgb[04][03][02][01]
 * ((unsigned char *)&trgb)[3] : 01
 */
unsigned char	ft_get_t(int trgb)
{
	return (((unsigned char *)&trgb)[3]);
}

unsigned char	ft_get_r(int trgb)
{
	return (((unsigned char *)&trgb)[2]);
}

unsigned char	ft_get_g(int trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

unsigned char	ft_get_b(int trgb)
{
	return (((unsigned char *)&trgb)[0]);
}
