/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:34:44 by mogawa            #+#    #+#             */
/*   Updated: 2023/08/25 14:41:27 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// # include <stdio.h>
// # include <unistd.h>
// # include <stdarg.h>
// # include <limits.h>

int		ft_printf(const char *fmt, ...);
int		ft_dprintf(int fd, const char *fmt, ...);
// ssize_t	ft_arg_handler_pf(int fd, char c, va_list *ap);
// ssize_t	ft_putchar_cnt_pf(int fd, char c);
// ssize_t	ft_putstr_cnt_pf(int fd, char *s);
// ssize_t	ft_putnbr_pf(int fd, unsigned long n, size_t base, char *nbr);
// ssize_t	ft_putnbr_int_pf(int fd, int n);

#endif