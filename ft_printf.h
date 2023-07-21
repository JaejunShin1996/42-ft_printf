/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:15:29 by jaeshin           #+#    #+#             */
/*   Updated: 2023/07/21 11:24:28 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_c_printf(int arg, int *count);
void	ft_c_printf2(char c, int *count);
void	ft_s_printf(char *arg, int *count);
void	ft_i_d_printf(int arg, int *count);
void	ft_u_printf(unsigned int arg, int *count);
void	ft_p_printf(size_t arg, int *count);
void	ft_x_printf(unsigned int arg, char c, int *count);

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_up_putstr(char *s);
size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);
char	*ft_u_itoa(unsigned int n);
char	*ft_pointer(size_t dec, int *count);
char	*ft_dtoh(unsigned int dec, int *count);

#endif