/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:34:29 by eviscont          #+#    #+#             */
/*   Updated: 2023/10/10 11:54:39 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	i = 0;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (i < n && c1[i] != '\0')
	{
		if (c2[i] == '\0')
			return (1);
		else if (c1[i] > c2[i])
			return (1);
		else if (c1[i] < c2[i])
			return (-1);
		i++;
	}
	if (i < n && (c1[i] == '\0' && c2[i] != '\0'))
		return (-1);
	return (0);
}

// int	main(void)
// {
// 	const char	s1[] = "ola";
// 	const char	s2[] = "Hola";
// 	int			r;

// 	r = (ft_strncmp(s1, s2, 4));
// 	printf("%d ", r);
// 	return (0);
// }