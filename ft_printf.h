/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:15:29 by jaeshin           #+#    #+#             */
/*   Updated: 2023/07/20 16:36:39 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_up_putstr(char *s);
size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);
char	*ft_u_itoa(unsigned int n);
char	*ft_pointer(size_t dec, int *count);
char	*ft_dtoh(unsigned int dec, int *count);

#endif