/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:17:19 by eviscont          #+#    #+#             */
/*   Updated: 2023/10/09 11:11:34 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*s;
	t_list	*tmp;

	if (lst != NULL && *lst != NULL && del != NULL)
	{
		s = *lst;
		while (s)
		{
			tmp = s->next;
			del(s->content);
			free(s);
			s = tmp;
		}
		*lst = NULL;
	}
}
