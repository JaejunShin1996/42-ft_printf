/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:17:29 by jaeshin           #+#    #+#             */
/*   Updated: 2023/07/18 18:56:27 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		result;
	va_list	args;
	int		value;

	result = 0;
	va_start(args, format);
	if (format == NULL)
		return (0);
	value = va_arg(args, int);
	printf("test: %i", value);
	while (*format)
	{
		if (*format == '%')
		{

		}
		else
		{
			ft_putchar(*format);
		}
		result++;
		format++;
	}
	return (result);
}

int	main(void)
{
	int	test;

	test = 123;
	ft_printf("42 Adelaide\n", test);
	return (0);
}
