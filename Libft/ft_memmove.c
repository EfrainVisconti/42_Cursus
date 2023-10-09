/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:46:16 by eviscont          #+#    #+#             */
/*   Updated: 2023/10/09 15:36:44 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	unsigned char		*org;
	size_t				i;

	dest = (unsigned char *)dst;
	org = (unsigned char *)src;
	if (dst == src || len == 0)
		return (dst);
	if (src < dst)
	{	
		i = len;
		while (i-- > 0)
		{
			dest[i] = org[i];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dest);
}

// int	main(void)
// {
// 	char	origen[] = "Hola, mundo!";
// 	char	destino[20];
// 	ft_memmove(destino, origen, 10);
// 	destino[4] = '\0';
// 	printf("Destino: %s\n", destino);
// 	return (0);
// }