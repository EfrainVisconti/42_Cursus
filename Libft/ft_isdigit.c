/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:59:50 by eviscont          #+#    #+#             */
/*   Updated: 2023/10/09 14:52:00 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	char	c;

// 	c = '8';
// 	if (ft_isdigit(c))
// 	{
// 		printf("%c es un caracter numerico\n", c);
// 	}
// 	else
// 	{
// 		printf("%c no es un caracter numerico\n", c);
// 	}
// 	return (0);
// }