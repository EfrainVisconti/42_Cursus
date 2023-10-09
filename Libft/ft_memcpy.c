/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:40:39 by eviscont          #+#    #+#             */
/*   Updated: 2023/10/09 15:27:42 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*dest;
	unsigned char	*org;

	i = 0;
	dest = (unsigned char *)dst;
	org = (unsigned char *)src;
	if (dst == src || n == 0)
		return (dst);
	while (i < n)
	{
		dest[i] = org[i];
		i++;
	}
	return (dst);
}

// int	main(void)
// {
// 	char origen[10] = "6789";
// 	char destino[10] = "123456789";
// 	printf("Antes: %s, %s\n", origen, destino);
// 	ft_memcpy(destino, origen, 4);
// 	printf("Despues: %s, %s\n", origen, destino);
// 	return (0);
// }