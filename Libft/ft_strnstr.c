/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:03:02 by eviscont          #+#    #+#             */
/*   Updated: 2023/09/21 15:28:56 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Es una función en el lenguaje de programación C que se utiliza
para buscar una subcadena dentro de una cadena de texto. La
función toma dos argumentos: la cadena en la que se va a buscar
la subcadena y la subcadena que se desea encontrar. A diferencia
de la función strstr, que busca la subcadena en la cadena
completa, strnstr tiene un tercer argumento que especifica la
longitud máxima de la búsqueda.*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*big;
	char	*little;
	size_t	i;
	size_t	j;

	big = (char *)haystack;
	little = (char *)needle;
	i = 0;
	if (little[i] == '\0')
		return (big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (little[j] == big[i + j] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return (&big[i]);
			j++;
		}
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	str[] = "Hola mundo!";
// 	char	str1 [] = "";
// 	char	*result;
	
// 	result = ft_strnstr(str, str1, 10);
// 	printf("resultado: %s\n", result);
// 	return (0);
// }
