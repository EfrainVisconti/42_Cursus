/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_to_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:56:55 by eviscont          #+#    #+#             */
/*   Updated: 2024/01/23 15:49:15 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_to_base(size_t c, char *base, int *length)
{
	size_t	len;

	len = 0;
	while (base[len] != '\0')
		len++;
	if (c >= len && len != 0)
	{
		ft_print_to_base(c / len, base, length);
		ft_print_to_base(c % len, base, length);
	}
	else
		ft_print_char(base[c], length);
}
