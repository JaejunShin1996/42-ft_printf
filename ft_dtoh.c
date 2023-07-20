/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:23:44 by jaeshin           #+#    #+#             */
/*   Updated: 2023/07/20 13:49:58 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	l_hex_size(long dec)
{
	int	size;
	
	size = 0;
	while (dec > 0)
	{
		dec /= 16;
		size++;
	}
	return (size);
}

char	*ft_l_dtoh(long dec, int *count)
{
	char	*result;
	int		size;
	
	size = l_hex_size(dec);
	*count += size + 2;
	result = (char *)malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[size--] = '\0';
	while (dec > 0)
	{
		result[size] = "0123456789abcdef"[dec % 16];
		dec /= 16;
		size--;
	}
	return (result);
}

int	hex_size(int dec)
{
	int	size;
	
	size = 0;
	while (dec > 0)
	{
		dec /= 16;
		size++;
	}
	return (size);
}

char	*ft_dtoh(int dec, int *count)
{
	char			*result;
	int				size;
	
	size = hex_size(dec);
	*count += size;
	result = (char *)malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[size--] = '\0';
	while (dec > 0)
	{
		result[size] = "0123456789abcdef"[dec % 16];
		dec /= 16;
		size--;
	}
	return (result);
}

char	*ft_m_dtoh(int dec, int *count)
{
	char	*result;
	int		size;
	int		s_temp;
	
	dec *= -1;
	size = hex_size(dec);
	s_temp = size;
	*count += size;
	result = (char *)malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[size--] = '\0';
	while (dec > 0)
	{
		result[size] = "0123456789abcdef"[dec % 16];
		dec /= 16;
		size--;
	}
	while (s_temp < 8)
		result[s_temp++] = 'f';
	return (result);
}
