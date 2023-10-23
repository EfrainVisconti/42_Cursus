/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:47:05 by eviscont          #+#    #+#             */
/*   Updated: 2023/10/18 13:31:05 by eviscont         ###   ########.fr       */
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

// int	main(void)
// {
// 	int	c;
// 	int	*lenght;
	
// 	lenght = 0;
// 	c = 'c';
// 	print_char(c, &lenght);
// 	printf("%d", lenght);
// 	return (0);
// }
