/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:25:18 by eviscont          #+#    #+#             */
/*   Updated: 2023/09/19 15:32:01 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*La función strrchr en C se utiliza para buscar la última ocurrencia
de un carácter específico en un string y devuelve un puntero al
último carácter encontrado o NULL si el carácter no está presente
en la cadena.*/

char	*ft_strrchr(const char *str, int c)
{
	char	d;
	char	*nstr;
	unsigned int	i;

	d = (char)c;
	nstr = (char *)str;
	i = ft_strlen(str);
	if (d == '\0')
		return (&nstr[i]);
	while (i > 0)
	{
		i--;
		if (nstr[i] == d)
			return (&nstr[i]);
	}
	return (0);
}

// int	main(void)
// {
//     const char *str = "Hola Mundo";
//     char character = 'u';

//     char *result = strrchr(str, character);

//     if (result != NULL) {
//         printf("El carácter '%c' fue encontrado por ultima vez en la posición %ld.\n", character, result - str);
//     } else {
//         printf("El carácter '%c' no fue encontrado en la cadena.\n", character);
//     }

//     return (0);
// }
