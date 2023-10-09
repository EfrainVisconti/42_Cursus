/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:20:57 by eviscont          #+#    #+#             */
/*   Updated: 2023/10/09 16:42:00 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	d;
	char	*nstr;

	d = (char)c;
	nstr = (char *)str;
	while (*nstr != '\0' && *nstr != d)
		nstr++;
	if (*nstr == d)
		return (nstr);
	return (0);
}

// int	main(void)
// {
//     const char *str = "Hola Mundo";
//     char character = 'a';
//     char *result = strchr(str, character);
// 	if (result != NULL)
// 		printf("'%c' encontrado, posición %ld.\n", character, result - str);
// 	else
// 		printf("'%c' no fue encontrado en la cadena.\n", character);
// 	return (0);
// }