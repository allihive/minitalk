/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:45:14 by alli              #+#    #+#             */
/*   Updated: 2023/11/24 15:42:18 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// int check_error(int arg, int len)
// {
//     if (arg < 0)
//         return (-1);
//     else
//         return (len);
// }

int print_format(char spec, va_list ap)
{
	if (spec == '%')
		return (ft_putchar('%'));
	else if (spec == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (spec == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (spec == 'd' || spec == 'i')
		return (ft_putnbr((long)va_arg(ap, int)));
	else if (spec == 'p')
	{
		if (ft_putstr("0x") < 0)
			return (-1);
		return (ft_ret_ptr(va_arg(ap, void *)) + 2);
	}
	else if (spec == 'u')
		return (ft_putnbr_u(va_arg(ap, unsigned int)));
	else if (spec == 'x')
		return (ft_hexnum_l(va_arg(ap, unsigned int)));
	else if (spec == 'X')
		return (ft_hexnum_u(va_arg(ap, unsigned int)));
	return (0);
	}

int ft_printf(const char *ap, ...)
{
	va_list	arg;
	va_start (arg, ap);
	int i;

	i = 0;
	while (*ap != '\0')
	{
		if (*ap == '%')
		{
			i += print_format(*(ap + 1), arg);
			if (i < 0)
				return (-1);
			ap++;
		}
		else
		{
			if (write (1, ap, 1) < 0)
				return (-1);
		i++;   
		}
		++ap;
	}
	va_end (arg);
	return (i);
}

// int main(void)
// {
// 	//int count;
//     //int variable = 0;
//     //char *ptr;

//     int i = ft_printf("%u\n", -2);
//     int j = printf("%u\n", -2);
//     printf("i = %d\n", i);
//     printf("j = %d\n", j);
// //     ptr = "this string";
// //     count = ft_printf("Hello %s\n", "YOU!"); 
// //     ft_printf("This prints the amount of letters in Hello You! = : %d\n", count);

// //     //ft_printf("Hel %s!", "world");
// //     ft_printf("The value is and the address is %p\n", ptr);
// //     printf("%p", ptr);
// //     ft_printf("Hexadecimal: %d, Decimal: %u\n", 255, 12345);

// //     count = printf("Hello %s\n", "YOU!");
// //     printf("This prints the amount of letters in Hello You! = : %d\n", count);

// //    // printf("Hel%lo, %s!", "world");
// //     printf("The value is %d and the address is %p\n", 42, variable);
// //     printf("Hexadecimal: %d, Decimal: %u", 255, 12345);

//     return (0);
// }
