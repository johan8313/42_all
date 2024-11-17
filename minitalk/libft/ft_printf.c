/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmarti <johmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:01:15 by johmarti          #+#    #+#             */
/*   Updated: 2024/03/13 13:09:07 by johmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_formats(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_printchar(va_arg(args, int));
	else if (format == 's')
		print_length += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		print_length += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		print_length += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		print_length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_length += ft_print_percent();
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		print_length;
	va_list	args;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			print_length += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			print_length += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}

/*
int main() {
	ft_printf("coucou %c %c %c %c fin\n", '1', '2', '3', '4');
}
*/
/*
int	main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    char c = 'Q';
	void * uptr = &c;
	unsigned int u = 15;
	int	d = 20;
	unsigned int x = 96478;
    ft_printf("my printf function (c): %c\n", c);
	printf("original printf (c): %c\n", c);
	ft_printf("my printf function (p) : %p\n", uptr);
	printf("original prinft (p) : %p\n", uptr);
	ft_printf("my printf function (u) : %u\n", u);
	printf("original prinft (u) : %u\n", u);
	ft_printf("my printf function (d) : %d\n", d);
	printf("original prinft (d) : %d\n", d);
	ft_printf("my printf function (x) : %x\n", x);
	printf("original prinft (x) : %x\n", x);
	ft_printf("my printf function (X) : %X\n", x);
	printf("original prinft (X) : %X\n", x);
	ft_printf("my printf function (pourcent) : 100%% \n");
	printf("original prinft (pourcent) : 100%% \n");
    //ft_printf(" char : %c", argv[1]);
	//ft_printf(" void : %p", argv[1]);
}
*/
