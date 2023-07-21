/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:48:23 by jaeshin           #+#    #+#             */
/*   Updated: 2023/07/21 11:48:24 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_c_printf(int arg, int *count)
{
	char	c_value;

	c_value = arg;
	ft_putchar(c_value);
	*count += 1;
}

void	ft_c_printf2(char c, int *count)
{
	ft_putchar(c);
	*count += 1;
}

void	ft_s_printf(char *arg, int *count)
{
	char	*s_value;

	s_value = arg;
	if (!s_value)
	{
		*count += 6;
		ft_putstr("(null)");
		return ;
	}
	*count += ft_strlen(s_value);
	ft_putstr(s_value);
}

void	ft_i_d_printf(int arg, int *count)
{
	int		i_value;
	char	*s_value;

	i_value = arg;
	s_value = ft_itoa(i_value);
	*count += ft_strlen(s_value);
	ft_putstr(s_value);
	free(s_value);
}

void	ft_u_printf(unsigned int arg, int *count)
{
	unsigned int	ui_value;
	char			*s_value;

	ui_value = arg;
	s_value = ft_u_itoa(ui_value);
	*count += ft_strlen(s_value);
	ft_putstr(s_value);
	free(s_value);
}
