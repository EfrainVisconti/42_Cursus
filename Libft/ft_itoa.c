/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:13:57 by eviscont          #+#    #+#             */
/*   Updated: 2023/09/29 13:18:03 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Genera una string que represente el valor entero recibido como argumento.
Los números negativos tienen que gestionarse.*/

#include "libft.h"

int	numblen(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	num;
	char	*str;
	int		len;

	if (n == 0)
		return (ft_strdup("0"));
	num = n;
	len = numblen(num);
	str = malloc((sizeof(char)) * (len + 1));
	if (str == NULL)
		return (0);
	str[len] = '\0';
	len--;
	if (num < 0)
	{
		str[0] = '-';
		num = num * -1;
	}
	while (num > 0)
	{
		str[len] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	return (str);
}

// int	main(void)
// {
// 	int	s;
// 	s = -1;
// 	printf("%s", ft_itoa(s));
// 	return(0);
// }