/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:37:03 by eviscont          #+#    #+#             */
/*   Updated: 2023/09/14 16:50:31 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
		return (0);
}

// int	main(void)
// {
// 	char	c;
// 	c = '?';

// 	if (ft_isalnum(c))
// 	{
// 		printf("%c es un alfanumerico", c);
// 	}
// 	else
// 	{
// 		printf("%c no es un alfanumerico", c);
// 	}
// 	return (0);
// }
