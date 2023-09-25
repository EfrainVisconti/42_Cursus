/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:34:29 by eviscont          #+#    #+#             */
/*   Updated: 2023/09/20 13:26:07 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*La función strncmp en C se utiliza para comparar dos cadenas
de caracteres hasta un número especificado de caracteres o hasta
que se encuentre un carácter nulo ('\0') en una de las cadenas.
Esta función compara los caracteres en las dos cadenas y devuelve
un valor entero que indica si las cadenas son iguales, si la
primera cadena es menor que la segunda o si la primera cadena
es mayor que la segunda.*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	i = 0;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (i < n && s1[i] != '\0')
	{
		if (c2[i] == '\0')
			return (1);
		else if (c1[i] > c2[i])
			return (1);
		else if (c1[i] < c2[i])
			return (-1);
		i++;
	}
	if (i < n && (s1[i] == '\0' && s2[i] != '\0'))
		return (-1);
	return (0);
}

// int	main(void)
// {
// 	const char	s1[] = "Hola";
// 	const char	s2[] = "Hola";
// 	int			r;

// 	r = (ft_strncmp(s1, s2, 4));
// 	printf("%d ", r);
// 	return (0);
// }