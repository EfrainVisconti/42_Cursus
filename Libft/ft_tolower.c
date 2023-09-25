/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:09:37 by eviscont          #+#    #+#             */
/*   Updated: 2023/09/19 11:14:19 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
	{
		c = c + 32;
	}
	return (c);
}

// int	main(void)
// {
// 	int	c;
// 	int d;	
// 	c = 66;
// 	d = ft_tolower(c);
// 	printf("Antes: %d ", c);
// 	printf("Despues: %d ", d);
// 	return(0);
// }
