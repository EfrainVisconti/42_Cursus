/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:59:26 by eviscont          #+#    #+#             */
/*   Updated: 2023/10/10 17:04:35 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	mag_numb(int n)
{
	int	i;

	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i *= 10;
	}
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	mag;

	if (fd < 0)
		return ;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	mag = mag_numb(n);
	while (mag > 0 && n != -2147483648)
	{
		ft_putchar_fd(((n / mag) + 48), fd);
		n %= mag;
		mag /= 10;
	}
}

// int	main(void)
// {
// 	int	num;

// 	num = 54321;
// 	ft_putnbr_fd(num, 1);
// 	return (0);
// }