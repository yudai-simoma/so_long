/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:58:55 by yshimoma          #+#    #+#             */
/*   Updated: 2023/03/22 20:19:27 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>
# include <stdlib.h>

extern int	g_error_flg;

int		ft_printf(const char *format, ...);
void	ap_puts(const char *a_format, va_list *a_ap, size_t *a_return_num);
void	put_char(char a_c, size_t *a_return_num);
void	put_str(char *a_str, size_t *a_return_num);
void	put_nbr(int a_nbr, size_t *a_return_num);
void	put_u_nbr(unsigned int a_nbr, size_t *a_return_num);
void	put_16_upper(unsigned int a_nbr, size_t *a_return_num);
void	put_16_lower(unsigned int a_nbr, size_t *a_return_num);
void	put_16_address(void *a_address, size_t *a_return_num);
void	put_size_t_nbr(size_t a_nbr, size_t *a_return_num);
char	*ft_itoa_p(int n);
char	*ft_u_itoa(unsigned int n);
char	*ft_16_itoa_upper(unsigned int n);
char	*ft_16_itoa_lower(unsigned int n);
char	*ft_16_address_itoa(uintptr_t n);
char	*ft_size_t_itoa(size_t n);
void	ft_putstr_fd_p(char *s, int fd);
void	*ft_calloc_p(size_t count, size_t size);
void	*ft_memset_p(void *b, int c, size_t len);
size_t	ft_strlen_p(const char *s);

#endif