/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:23:53 by ygunay            #+#    #+#             */
/*   Updated: 2022/08/17 19:11:30 by ygunay           ###   ########.fr       */
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
		len += ft_printstr(va_arg(args, char *));
	// else if (format == 'p')
	// 	len += ft_printptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		len += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_print_unsigned(va_arg(args, unsigned int));
	// else if (format == 'x' || format == 'X')
	// 	len += ft_print_hexa(va_arg(args, unsigned int), format);
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

int main(void)

{
char s1 ='a';
printf("or char %c\n",s1);
char s2 ='a';
ft_printf("ft char %c\n",s2);



char str1[] ="abc";
printf("or char %s\n",str1);
char str2[] ="abc";
ft_printf("ft char %s\n",str2);


int nbr1 =-123;
printf("or int %d\n",nbr1);
int nbr2 =-123;
ft_printf("ft int %d\n",nbr2);



int unbr1 =123;
printf("or udecimal %u\n",nbr1);
int unbr2 =123;
ft_printf("ft udecimal %u\n",nbr2);


// int var =10;
// int *ptr;
// ptr = &var;
int a =1;
printf("or pointer %p\n",&a);


return 0;
}