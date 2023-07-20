/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:17:29 by jaeshin           #+#    #+#             */
/*   Updated: 2023/07/20 18:22:05 by jaeshin          ###   ########.fr       */
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
	if (!s_value)
	{
		*count += 6;
		ft_putstr("(null)");
		return ;
	}
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
	free(s_value);
}

void	ft_p_printf(va_list arg, int *count)
{
	size_t	p_value;
	char	*result;

	p_value = (size_t)va_arg(arg, void *);
	if (!p_value)
	{
		ft_putstr("0x0");
		*count += 3;
		return ;
	}
	result = ft_pointer(p_value, count);
	ft_putstr("0x");
	ft_putstr(result);
	free(result);
}

void	ft_u_printf(va_list arg, int *count)
{
	unsigned int	ui_value;
	char			*s_value;

	ui_value = va_arg(arg, unsigned int);
	s_value = ft_u_itoa(ui_value);
	*count += ft_strlen(s_value);
	ft_putstr(s_value);
	free(s_value);
}

void	ft_x_printf(va_list arg, char c, int *count)
{
	unsigned int	i_value;
	char			*result;

	i_value = (unsigned int)va_arg(arg, unsigned int);
	if (i_value != 0)
		result = ft_dtoh(i_value, count);
	else
	{
		ft_putchar('0');
		*count += 1;
		return ;
	}
	if (c == 'x')
		ft_putstr(result);
	else if (c == 'X')
		ft_up_putstr(result);
	free(result);
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
			else if (*format == 'x' || *format == 'X')
				ft_x_printf(args, *format, &result);
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

	test = -9;
	result = ft_printf("p-%p x-%x\n", (void *)-1, -1);
	result2 = printf("p-%p x-%x\n", (void *)-1, -1);
	printf("%i\n%i\n", result, result2);
	return (0);
}
