/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:25:18 by eviscont          #+#    #+#             */
/*   Updated: 2023/10/09 16:56:03 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char			d;
	char			*nstr;
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
// 	const char *str = "Hola Mundou";
// 	char character = 'u';
// 	char *result = strrchr(str, character);
// 	if (result != NULL)
// 		printf("'%c' encontrado, posición %ld.\n", character, result - str);
// 	else
// 		printf("'%c' no fue encontrado en la cadena.\n", character);
//     return (0);
// }