/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:41:07 by jaeshin           #+#    #+#             */
/*   Updated: 2023/07/19 17:41:25 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	n_convert(unsigned int n)
{
	unsigned int	temp;

	temp = 0;
	if (n < 0)
		temp = -n;
	else
		temp = n;
	return (temp);
}

static size_t	size_getter(unsigned int n)
{
	size_t			size;
	unsigned int	temp;

	size = 0;
	temp = n_convert(n);
	if (n <= 0)
		size++;
	while (temp > 0)
	{
		size++;
		temp /= 10;
	}
	return (size);
}

char	*ft_uitoa(unsigned int n)
{
	size_t			size;
	char			*result;
	unsigned int	temp;

	size = size_getter(n);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (result == NULL)
		return (NULL);
	if (n == 0)
		result[0] = '0';
	temp = n_convert(n);
	result[size] = '\0';
	size--;
	while (0 < temp)
	{
		result[size] = temp % 10 + '0';
		temp /= 10;
		size--;
	}
	if (n < 0)
		result[size] = '-';
	return (result);
}