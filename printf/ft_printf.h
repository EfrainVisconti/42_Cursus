/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:57:20 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/31 12:36:06 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

# define HEXA_MA	"0123456789ABCDEF"
# define HEXA_MI	"0123456789abcdef"

int		ft_printf(const char *s, ...);
void	ft_print_char(int c, int *length);
void	ft_print_number(int c, int *length);
void	ft_print_pointer(size_t c, int *length);
void	ft_print_str(char *s, int *length);
void	ft_print_to_base(size_t c, char *base, int *length);
void	ft_print_unsign(long int c, int *length);

#endif