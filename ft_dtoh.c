/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:23:44 by jaeshin           #+#    #+#             */
/*   Updated: 2023/07/20 18:20:43 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pointer_size(size_t dec)
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

char	*ft_pointer(size_t dec, int *count)
{
	char	*result;
	int		size;

	size = pointer_size(dec);
	*count += size + 2;
	result = (char *)malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[size--] = '\0';
	while (dec > 0)
	{
		printf("%li\n", dec);
		result[size] = "0123456789abcdef"[dec % 16];
		dec /= 16;
		size--;
	}
	return (result);
}

int	hex_size(unsigned int dec)
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

char	*ft_dtoh(unsigned int dec, int *count)
{
	char	*result;
	int		size;

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
