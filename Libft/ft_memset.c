/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:57:14 by eviscont          #+#    #+#             */
/*   Updated: 2023/09/14 18:27:07 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)b;
	while (i < len)
	{
		ptr[i] = c;
		i++;
	}
	return (b);
}

// int main()
// {
//     char str[50] = "Veneco";
//     printf("\nBefore memset(): %s\n", str);
// 	ft_memset(str , 'a', 3);
//     printf("After memset():  %s", str);
//     return 0;
// }
