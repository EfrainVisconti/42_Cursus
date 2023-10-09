/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:37:24 by eviscont          #+#    #+#             */
/*   Updated: 2023/10/09 14:50:49 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

// int	main(void)
// {
// 	char	c;

// 	c = 52;
// 	if (ft_isascii(c))
// 	{
// 		printf("%c es caracter ascii\n", c);
// 	}
// 	else
// 	{
// 		printf("%c no es caracter ascii\n", c);
// 	}	
// 	return (0);
// }
