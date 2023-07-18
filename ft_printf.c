/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:17:29 by jaeshin           #+#    #+#             */
/*   Updated: 2023/07/18 15:18:11 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		result;
	va_list	ptr;

	result = (int)ft_strlen(format);
	ft_putstr((char *)format);
	return (result);
}

int	main(void)
{
	int	test;

	test = 1234;
	ft_printf("42 Adelaide");
	return (0);
}
