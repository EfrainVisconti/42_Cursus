/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:45:15 by eviscont          #+#    #+#             */
/*   Updated: 2023/09/28 16:53:26 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*A cada carácter de la string ’s’, aplica la función ’f’ dando como
parámetros el índice de cada carácter dentro de ’s’ y el propio carácter.
Genera una nueva string con el resultado del uso sucesivo de ’f’*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	i = 0;
	if (s == NULL || f == NULL)
		return (0);
	str = (char *)malloc(ft_strlen(s) + 1);
	if (str == NULL)
		return (0);
	while (i < ft_strlen(s))
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
// char	fun(unsigned int i, char d)
// {
// 	int	n;

// 	n = i;
// 	return (d - 3);
// }

// int	main()
// {
// 	char	*d;

// 	d = ft_strmapi("Krod#pxqgr", fun);
// 	printf("%s", d);
// 	free(d);
// 	return 0;
// }
