/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:49:39 by eviscont          #+#    #+#             */
/*   Updated: 2023/10/17 16:05:46 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_getformat(char c, )

int	ft_printf(const char *s, ...)
{
	va_list	args;
	

	va_start(args, s);

	va_arg(args, *void);

	va_end(args);
}
