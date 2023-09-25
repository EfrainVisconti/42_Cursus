/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:42:19 by eviscont          #+#    #+#             */
/*   Updated: 2023/09/23 14:28:12 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			src_len;
	unsigned int	i;

	src_len = 0;
	i = 0;
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	if (dstsize != 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

// int	main(void)
// {
// 	char	src[] = "hola mundo";
// 	char	dest[] = "prueba de cadena";
// 	printf("antes: %s, %s\n", src, dest);
// 	ft_strlcpy(dest, src, 7);
// 	printf("despues: %s, %s\n", src, dest);
// 	printf("tamaño: %zu", ft_strlcpy(dest, src, 7));
// 	return (0);
// }