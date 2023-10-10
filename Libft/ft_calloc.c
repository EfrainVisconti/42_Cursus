/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:00:24 by eviscont          #+#    #+#             */
/*   Updated: 2023/10/10 13:54:29 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	result = malloc(count * size);
	if (result == 0)
		return (0);
	else
	{
		ft_bzero(result, (count * size));
		return (result);
	}
}

// int	main(void)
// {
// 	int	*arr;
// 	size_t	numelem;
// 	size_t	i;

// 	i = 0;
// 	numelem = 2;
// 	arr = (int *)ft_calloc(numelem, sizeof(int));
// 	if (arr == 0)
// 	{
// 		printf("Error al asignar memoria. \n");
// 		return (1);
// 	}
// 	while (i < numelem)
// 	{
// 		printf("%d ", arr[i]);
// 		i++;
// 	}
// 	free(arr);
// 	return (0);
// }