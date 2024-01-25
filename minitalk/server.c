/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:24:48 by eviscont          #+#    #+#             */
/*   Updated: 2024/01/23 16:52:50 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int signal)
{
	static int				bit;
	static unsigned char	c;

	c <<= 1;
	if (signal == SIGUSR1)
		c |= 1;
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = '\0';
	}
}

static void	get_pid(void)
{
	int	pid;

	pid = getpid();
	if (!pid)
		ft_printf("Error generating process ID");
	ft_printf("The ID of the server is: %i\n", pid);
}

int	main(void)
{
	get_pid();
	ft_printf("Waiting...\n");
	while (1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
	}
	return (0);
}
