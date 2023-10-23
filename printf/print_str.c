/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:24:08 by eviscont          #+#    #+#             */
/*   Updated: 2023/10/18 13:55:17 by eviscont         ###   ########.fr       */
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

void	print_str(char *s, int *lenght)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			print_char(s[i], lenght);
			i++;
		}
	}
}

// int	main(void)
// {
// 	char	s[20] = "Hola";
// 	int		*lenght;

// 	lenght = 0;
// 	print_str(s, &lenght);
// 	printf("%d", lenght);
// 	return (0);
// }