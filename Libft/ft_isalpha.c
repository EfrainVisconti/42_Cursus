/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:38:39 by eviscont          #+#    #+#             */
/*   Updated: 2023/09/14 16:52:03 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

// int main(void)
// {
// 	char c;
// 	c = ' ';

// 	if (ft_isalpha(c))
// 	{
// 		printf("%c es una letra\n", c);
// 	}
// 	else
// 	{
// 		printf("%c no es una letra\n", c);
// 	}

// 	return (0);
// }