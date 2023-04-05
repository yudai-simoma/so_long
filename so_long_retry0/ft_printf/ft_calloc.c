/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:21:32 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/20 18:34:34 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** 指定バイト分メモリ領域をn個分確保する
*/
void	*ft_calloc_p(size_t count, size_t size)
{
	unsigned char	*src;

	if (size > 0 && count > SIZE_MAX / size)
		return (NULL);
	src = (unsigned char *)malloc(size * count);
	if (src == NULL)
		return (NULL);
	ft_memset_p(src, '\0', (size * count));
	return ((void *)src);
}
