/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:09:30 by eviscont          #+#    #+#             */
/*   Updated: 2023/09/28 18:47:42 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Envía el carácter ’c’ al file descriptor especificado.*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
