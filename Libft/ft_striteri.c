/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:55:02 by eviscont          #+#    #+#             */
/*   Updated: 2023/10/10 16:20:31 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void	fu(unsigned int i, char *c)
// {
// 	i = 0;
// 	while (c[i])
// 	{
// 		c[i] = 'A';
// 		i++;
// 	}
// }

// int	main(void)
// {
// 	char	d[] = "Hola Mundo!";

// 	ft_striteri(d, &fu);
// 	printf("%s", d);
// 	return (0);
// }