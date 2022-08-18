/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:23:53 by ygunay            #+#    #+#             */
/*   Updated: 2022/08/18 16:10:31 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		len += ft_print_ptr(va_arg(args, unsigned long ));
	else if (format == 'd' || format == 'i')
		len += ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_print_hexa(va_arg(args, unsigned int), format);
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, str);
	len = 0;
	i = 0;
	while (str && str[i])
	{
		if (str[i] == '%')
		{
			len += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

// int main(void)

// {
// char s1 ='a';
// printf("or char %c\n",s1);
// char s2 ='a';
// ft_printf("ft char %c\n",s2);

// char str1[] ="abc";
// printf("or char %s\n",str1);
// char str2[] ="abc";
// ft_printf("ft char %s\n",str2);

// int nbr1 =-123;
// printf("or int d %d\n",nbr1);
// int nbr2 =-123;
// ft_printf("ft int d %d\n",nbr2);

// int nbr3 =-123;
// printf("or int i %i\n",nbr3);
// int nbr4 =-123;
// ft_printf("ft int i %i\n",nbr4);

// int unbr =123;
// printf("or udecimal %u\n",unbr);
// ft_printf("ft udecimal %u\n",unbr);

// int a1= 123;
// int *ptr =&a1;
// printf("or pointer %p\n",ptr);
// ft_printf("ft pointer %p\n",ptr);

// int b1 = 123;
// printf("or hexa x %x\n",b1);
// int b2 = 123;
// ft_printf("ft hexa x %x\n",b2);

// int b3 = 123;
// printf("or hexa X %X\n",b3);
// int b4 = 123;
// ft_printf("ft hexa X %X\n",b4);

// printf("or %%\n");
// ft_printf("ft %%\n");
// return 0;
// }
