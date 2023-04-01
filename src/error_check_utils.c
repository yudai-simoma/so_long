/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:49:59 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/30 19:18:11 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_file_check(char *a_name, t_error	*a_error)
{
	if (a_name[a_error->name_len - 4] != '.'
		|| a_name[a_error->name_len - 3] != 'b'
		|| a_name[a_error->name_len - 2] != 'e'
		|| a_name[a_error->name_len - 1] != 'r')
		return (1);
	return (0);
}
