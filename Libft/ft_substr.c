/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:59:48 by eviscont          #+#    #+#             */
/*   Updated: 2023/09/28 11:05:47 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Reserva (con malloc(3)) y devuelve una substring de la string ’s’.
La substring empieza desde el índice ’start’ y tiene una longitud
máxima ’len’.*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sb;
	unsigned int	i;

	i = 0;
	if (s == 0)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sb = (char *)malloc(len + 1);
	if (sb == 0)
		return (0);
	while (i < len)
	{
		sb[i] = s[start];
		start++;
		i++;
	}
	sb[i] = '\0';
	return (sb);
}

// int	main()
// {
// 	char	s[] = "Hola Mundo!";
// 	printf("nueva: %s", ft_substr(s, 3, 3));
// 	return (0);
// }
