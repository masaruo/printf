/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:41:06 by mogawa            #+#    #+#             */
/*   Updated: 2023/08/25 14:41:19 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"
#include "unistd.h"

static int	ft_xprintf(int fd, const char *fmt, va_list ap)
{
	return (ft_dprintf(fd, fmt, ap));
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, fmt);
	len = ft_xprintf(STDOUT_FILENO, fmt, ap);
	va_end(ap);
	return (len);
}

int	ft_dprintf(int fd, const char *fmt, ...)
{
	va_list	ap;
	int		n;
	ssize_t	len;

	n = 0;
	len = 0;
	va_start(ap, fmt);
	while (fmt[n])
	{
		if (fmt[n] == '%')
		{
			n++;
			len += ft_arg_handler_pf(fd, fmt[n], &ap);
		}
		else
			len += ft_putchar_cnt_pf(fd, fmt[n]);
		n++;
	}
	va_end(ap);
	return ((int)len);
}
