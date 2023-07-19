/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:17:29 by jaeshin           #+#    #+#             */
/*   Updated: 2023/07/19 12:18:33 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		result;
	va_list	args;
	char	c_value;
	int		i_value;
	char	*s_value;

	result = 0;
	c_value = 0;
	i_value = 0;
	s_value = "";
	va_start(args, format);
	if (format == NULL)
		return (0);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c_value = va_arg(args, int);
				ft_putchar(c_value);
			}
			else if (*format == 's')
			{
				s_value = va_arg(args, char *);
				ft_putstr(s_value);
				while (*s_value)
				{
					result++;
					s_value++;
				}
			}
			else if (*format == 'i')
			{
				i_value = va_arg(args, int);
				s_value = ft_itoa(i_value);
				ft_putstr(s_value);
			}
		}
		else
			ft_putchar(*format);
		result++;
		format++;
	}
	return (result);
}

int	main(void)
{
	int	test;

	test = 123;
	ft_printf("ft - name is %c and I am %i %s.\n", 'J', 27, "years old");
	printf("og - name is %c and I am %i %s.\n", 'J', 27, "years old");
	return (0);
}
