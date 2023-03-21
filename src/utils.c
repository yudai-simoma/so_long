/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:21:55 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/21 18:47:08 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// size_t	ft_arr_size_pp(char **a_str)
// {
// 	size_t	i;

// 	// ft_printf("a_str[4] = %s\n", a_str[4]);
// 	// ft_printf("a_str[5] = %s\n", a_str[5]);
// 	// ft_printf("a_str[6] = %s\n", a_str[6]);
// 	i = 0;
// 	while (a_str[i] != NULL)
// 		i++;
// 	return (i);
// }

void	ft_map_len(t_vars *r_vars)
{
	size_t	i;

	i = 0;
	while (r_vars->map_str[i] != NULL)
		i++;
	r_vars->column = i;
	r_vars->record = ft_strlen(r_vars->map_str[0]) - 1;
}
