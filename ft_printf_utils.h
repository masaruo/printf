#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include <sys/types.h>
# include <stdarg.h>

ssize_t	ft_arg_handler_pf(int fd, char c, va_list *ap);
ssize_t	ft_putchar_cnt_pf(int fd, char c);
ssize_t	ft_putstr_cnt_pf(int fd, char *s);
ssize_t	ft_putnbr_pf(int fd, unsigned long n, size_t base, char *nbr);
ssize_t	ft_putnbr_int_pf(int fd, int n);

#endif