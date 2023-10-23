/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:00:20 by eviscont          #+#    #+#             */
/*   Updated: 2023/10/18 15:56:39 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_char(int c, int *lenght)
{
	if (*lenght == -1)
		return ;
	if (write(1, &c, 1) == -1)
		return ;
	else
		*lenght = *lenght + 1;
}

void	print_number(int c, int *lenght)
{
	if (c == -2147483648)
	{
		write(1, "-2147483648", 11);
		*lenght = *lenght + 11;
	}
	else if (c < 0)
	{
		print_char('-', lenght);
		print_number(c * -1, lenght);
	}
	else if (c > 9)
	{
		print_number(c / 10, lenght);
		print_number(c % 10, lenght);
	}
	else
		print_char(c + 48, lenght);
}

int	main(void)
{
	int	c;
	int	*lenght;

	lenght = 0;
	c = 214748;
	print_number(c, &lenght);
	printf("\n%d", lenght);
	return (0);
}