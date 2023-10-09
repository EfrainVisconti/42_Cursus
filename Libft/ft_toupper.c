/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:41:06 by eviscont          #+#    #+#             */
/*   Updated: 2023/10/09 16:28:33 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
	{
		c = c - 32;
	}
	return (c);
}

// int	main(void)
// {
// 	int	c;
// 	int d;
// 	c = 120;
// 	d = ft_toupper(c);
// 	printf("Antes: %d ", c);
// 	printf("Despues: %d ", d);
// 	return(0);
// }