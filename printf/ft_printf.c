/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:49:39 by eviscont          #+#    #+#             */
/*   Updated: 2023/11/02 17:49:47 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_format(va_list *list, char c, int *length)
{
	if (c == 'c')
		ft_print_char(va_arg(*list, int), length);
	else if (c == 's')
		ft_print_str(va_arg(*list, char *), length);
	else if (c == 'p')
		ft_print_pointer(va_arg(*list, size_t), length);
	else if (c == 'i' || c == 'd')
		ft_print_number(va_arg(*list, int), length);
	else if (c == 'u')
		ft_print_unsign(va_arg(*list, unsigned int), length);
	else if (c == 'x')
		ft_print_to_base(va_arg(*list, unsigned int), HEXA_MI, length);
	else if (c == 'X')
		ft_print_to_base(va_arg(*list, unsigned int), HEXA_MA, length);
	else if (c == '%')
		ft_print_char('%', length);
	if (*length == -1)
		return (-1);
	return (1);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		length;
	int		i;

	if (!s)
		return (0);
	length = 0;
	va_start(list, s);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			if (ft_get_format(&list, s[++i], &length) == -1)
				return (-1);
			i++;
		}
		else
		{
			ft_print_char(s[i], &length);
			i++;
		}	
	}
	va_end(list);
	return (length);
}

// int	main(void)
// {
// 	int		number = 0;
// 	int		*ptr = NULL;

// 	ft_printf("%x\n", number);
// 	ft_printf("%X\n", number);
// 	ft_printf("%d\n", number);
// 	ft_printf("%i\n", number);
// 	ft_printf("%u\n", number);
// 	ft_printf("%s\n", "");
// 	ft_printf("%s\n", NULL);
// 	ft_printf("%c\n", 'd');
// 	ft_printf("%%\n");
// 	ft_printf("%p\n", (void *)ptr);
// 	printf("----\n");
// 	printf("%x\n", number);
// 	printf("%X\n", number);
// 	printf("%d\n", number);
// 	printf("%i\n", number);
// 	printf("%u\n", number);
// 	printf("%s\n", "");
// 	printf("%s\n", NULL);
// 	printf("%c\n", 'd');
// 	printf("%%\n");
// 	printf("%p\n", (void *)ptr);
// }