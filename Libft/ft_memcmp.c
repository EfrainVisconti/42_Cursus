/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:07:48 by eviscont          #+#    #+#             */
/*   Updated: 2023/09/21 19:11:43 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Se utiliza para comparar dos bloques de memoria byte a byte.
Esta función compara los primeros n bytes de dos bloques de
memoria y determina si son iguales, mayores o menores.*/

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)ptr1;
	str2 = (unsigned char *)ptr2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
//     char	str1[] = "Hell";
//     char	str2[] = "Hello";
//     int		result;

// 	result = ft_memcmp(str1, str2, 5);
// 	if (result == 0)
// 	{
// 		printf("Los bloques de memoria son iguales.\n");
// 	}
// 	else if (result < 0)
// 	{
// 		printf("El bloque 1 es menor que el bloque 2.\n");
// 	}
// 	else 
// 	{
// 		printf("El bloque 1 es mayor que el bloque 2.\n");
// 	}
// 	return (0);
// }