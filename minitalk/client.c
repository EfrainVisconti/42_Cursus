/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:24:45 by eviscont          #+#    #+#             */
/*   Updated: 2024/01/24 15:12:40 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	neg;

	i = 0;
	neg = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * neg);
}

static void	kill_check(int pid, int signal)
{
	if (kill(pid, signal) == -1)
	{
		ft_printf("Error delivering signal");
		exit(EXIT_FAILURE);
	}
}

static void	send_str(int pid, char *str)
{
	int	letter;
	int	bit;

	letter = 0;
	while (str[letter])
	{
		bit = 7;
		while (bit >= 0)
		{
			if (((str[letter] >> bit) & 1) == 1)
				kill_check(pid, SIGUSR1);
			else
				kill_check(pid, SIGUSR2);
			usleep(1000);
			bit--;
		}
		letter++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (!pid)
		{
			ft_printf("Error, wrong process ID");
			return (0);
		}
		if (argv[2][0] == 0)
		{
			ft_printf("Error, empty message");
			return (0);
		}
		send_str(pid, argv[2]);
		send_str(pid, "\n");
	}
	else
	{
		ft_printf("Error, wrong number of arguments");
	}
	return (0);
}
