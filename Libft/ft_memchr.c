/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:27:53 by eviscont          #+#    #+#             */
/*   Updated: 2023/09/20 15:20:55 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*La función memchr en el lenguaje de programación C se
utiliza para buscar la primera aparición de un byte
específico en un bloque de memoria.*/

void	*ft_memchr(const void *ptr, int value, size_t n)
{
	unsigned char	*str;
	unsigned char	v;
	size_t	i;

	str = (unsigned char *)ptr;
	v = (unsigned char)value;
	i = 0;
	while (i < n)
	{
		if (str[i] == v)
			return ((void *)(&str[i]));
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	str[] = "Hola mundo";
// 	char	*result = (char *)ft_memchr(str, 'm', 5);

// 	if (result != NULL)
// 		printf("Encontrado: %c\n", *result);
// 	else
// 		printf("No encontrado.\n");
// 	return (0);
// }
