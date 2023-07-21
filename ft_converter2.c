/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:48:43 by jaeshin           #+#    #+#             */
/*   Updated: 2023/07/21 11:48:44 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_p_printf(size_t arg, int *count)
{
	size_t	p_value;
	char	*result;

	p_value = arg;
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

void	ft_x_printf(unsigned int arg, char c, int *count)
{
	unsigned int	i_value;
	char			*result;

	i_value = arg;
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
