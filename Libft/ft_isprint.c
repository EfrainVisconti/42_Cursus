/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:10:27 by eviscont          #+#    #+#             */
/*   Updated: 2023/10/09 14:56:30 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	char	c;

// 	c = 120;
// 	if (ft_isprint(c))
// 	{
// 		printf("%c es un caracter imprimible\n", c);
// 	}
// 	else
// 	{
// 		printf("%c no es un caracter imprimible\n", c);
// 	}
// 	return (0);
// }