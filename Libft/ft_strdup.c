/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:12:25 by eviscont          #+#    #+#             */
/*   Updated: 2023/09/25 13:07:41 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Se utiliza para crear una copia de una cadena dada. La función toma
como entrada una cadena C terminada en nulo y asigna memoria para crear
una nueva cadena que es una copia exacta de la cadena de entrada.*/

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	size;
    char	*d;

	i = 0;
	size = ft_strlen((char *)s) + 1;
    d = (char *)malloc(size);
	if (d == 0)
		return (NULL);
	while (s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
