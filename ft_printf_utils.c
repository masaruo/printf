/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <masaruo@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:05:27 by mogawa            #+#    #+#             */
/*   Updated: 2025/06/23 22:56:31 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// outputs the string 's' to the file 'fd'
ssize_t	ft_putstr_cnt_pf(int fd, char *s)
{
	char	*str;
	ssize_t	n;

	n = 0;
	if (s == NULL)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	str = s;
	while (*str)
	{
		n += ft_putchar_cnt_pf(fd, *str);
		str++;
	}
	return (n);
}

ssize_t	ft_putchar_cnt_pf(int fd, char c)
{
	ssize_t	n;
	(void) fd;

	n = write(STDOUT_FILENO, &c, 1);
	return (n);
}

// remember to pass va_list ap as a pointer so that va_arg can move forward
ssize_t	ft_arg_handler_pf(int fd, char c, va_list *ap)
{
	ssize_t	n;

	n = 0;
	if (c == '%')
		n = ft_putchar_cnt_pf(fd, '%');
	else if (c == 'c')
		n = ft_putchar_cnt_pf(fd, va_arg(*ap, int));
	else if (c == 's')
		n = ft_putstr_cnt_pf(fd, va_arg(*ap, char *));
	else if (c == 'p')
	{
		n = ft_putstr_cnt_pf(fd, "0x");
		n += ft_putnbr_pf(fd, va_arg(*ap, unsigned long), 16, \
													"0123456789abcdef");
	}
	else if (c == 'd' || c == 'i')
		n = ft_putnbr_int_pf(fd, va_arg(*ap, int));
	else if (c == 'u')
		n = ft_putnbr_pf(fd, va_arg(*ap, unsigned int), 10, "0123456789");
	else if (c == 'x')
		n = ft_putnbr_pf(fd, va_arg(*ap, unsigned int), 16, "0123456789abcdef");
	else if (c == 'X')
		n = ft_putnbr_pf(fd, va_arg(*ap, unsigned int), 16, "0123456789ABCDEF");
	return (n);
}

/* https://stackoverflow.com/questions/3369588/
pass-va-list-or-pointer-to-va-list
*/
