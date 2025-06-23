/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:11:17 by mogawa            #+#    #+#             */
/*   Updated: 2023/06/20 15:31:01 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// output int 'n'
ssize_t	ft_putnbr_pf(int fd, unsigned long n, size_t base, char *nbr)
{
	ssize_t	len;

	len = 0;
	if (n >= base)
	{
		len += ft_putnbr_pf(fd, n / base, base, nbr);
		len += ft_putnbr_pf(fd, n % base, base, nbr);
	}
	else
	{
		len += ft_putchar_cnt_pf(fd, nbr[n % base]);
	}
	return (len);
}

ssize_t	ft_putnbr_int_pf(int fd, int n)
{
	ssize_t	len;

	len = 0;
	if (n < 0)
		len += ft_putchar_cnt_pf(fd, '-');
	if (n <= -10)
	{
		len += ft_putnbr_int_pf(fd, (n / 10) * -1);
		len += ft_putnbr_int_pf(fd, (n % 10) * -1);
	}
	else if (n >= 10)
	{
		len += ft_putnbr_int_pf(fd, n / 10);
		len += ft_putnbr_int_pf(fd, n % 10);
	}
	else if (10 > n && n > -10)
	{
		if (n < 0)
			n = n * -1;
		len += ft_putchar_cnt_pf(fd, n + '0');
	}
	return (len);
}
