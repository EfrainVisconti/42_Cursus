/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:08:56 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/31 12:36:30 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsign(long int c, int *length)
{
	if (c < 0)
	{
		ft_print_unsign(c * -1, length);
	}
	else if (c > 9)
	{
		ft_print_unsign(c / 10, length);
		ft_print_unsign(c % 10, length);
	}
	else
		ft_print_char(c + 48, length);
}
