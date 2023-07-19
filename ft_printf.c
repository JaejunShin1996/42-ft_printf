/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:17:29 by jaeshin           #+#    #+#             */
/*   Updated: 2023/07/19 18:53:20 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_c_printf2(char c, int *count)
{
	ft_putchar(c);
	*count += 1;
}

void	ft_c_printf(va_list arg, int *count)
{
	char	c_value;

	c_value = va_arg(arg, int);
	ft_putchar(c_value);
	*count += 1;
}

void	ft_s_printf(va_list arg, int *count)
{
	char	*s_value;

	s_value = va_arg(arg, char *);
	*count += ft_strlen(s_value);
	ft_putstr(s_value);
}

void	ft_i_d_printf(va_list arg, int *count)
{
	int		i_value;
	char	*s_value;

	i_value = va_arg(arg, int);
	s_value = ft_itoa(i_value);
	*count += ft_strlen(s_value);
	ft_putstr(s_value);
}

void	ft_p_printf(va_list arg, int *count)
{
	long	p_value;
	char	*hexa_base;
	
	hexa_base = "0123456789abcdef";
	p_value = (long)va_arg(arg, void *);
	while (p_value >= 16)
	{
		printf("%c ", hexa_base[p_value % 16]);
		p_value /= 16;
	}
	printf("%c ", hexa_base[p_value % 16]);
}

void	ft_u_printf(va_list arg, int *count)
{
	unsigned int	ui_value;
	char			*s_value;
	
	ui_value = va_arg(arg, unsigned int);
	s_value = ft_uitoa(ui_value);
	*count += ft_strlen(s_value);
	ft_putstr(s_value);
}

int	ft_printf(const char *format, ...)
{
	int		result;
	va_list	args;

	result = 0;
	va_start(args, format);
	if (format == NULL)
		return (0);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				ft_c_printf(args, &result);
			else if (*format == 's')
				ft_s_printf(args, &result);
			else if (*format == 'i' || *format == 'd')
				ft_i_d_printf(args, &result);
			else if (*format == 'p')
				ft_p_printf(args, &result);
			else if (*format == 'u')
				ft_u_printf(args, &result);
			else if (*format == '%')
				ft_c_printf2('%', &result);
		}
		else
			ft_c_printf2(*format, &result);
		format++;
	}
	return (result);
}

int	main(void)
{
	int	result;
	int	result2;
	int	test;

	test = 1;
	result = ft_printf("c-%c i-%i d-%d s-%s u-%u p-%p %%\n", 'J', 27, 178, "42Adeladie", -2, &test);
	result2 = printf("c-%c i-%i d-%d s-%s u-%u p-%p %%\n", 'J', 27, 178, "42Adeladie", -2, &test);
	printf("%i\n%i\n", result, result2);
	return (0);
}
