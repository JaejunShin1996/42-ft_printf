/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:17:29 by jaeshin           #+#    #+#             */
/*   Updated: 2023/07/21 12:09:36 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_check(char c, va_list ap, int *result)
{
	if (c == 'c')
		ft_c_printf(va_arg(ap, int), result);
	else if (c == 's')
		ft_s_printf(va_arg(ap, char *), result);
	else if (c == 'i' || c == 'd')
		ft_i_d_printf(va_arg(ap, int), result);
	else if (c == 'u')
		ft_u_printf(va_arg(ap, unsigned int), result);
	else if (c == '%')
		ft_c_printf2('%', result);
	else if (c == 'p')
		ft_p_printf(va_arg(ap, size_t), result);
	else if (c == 'x' || c == 'X')
		ft_x_printf(va_arg(ap, unsigned int), c, result);
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
			convert_check(*++format, args, &result);
		else
			ft_c_printf2(*format, &result);
		format++;
	}
	va_end(args);
	return (result);
}
