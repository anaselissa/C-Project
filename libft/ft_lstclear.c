/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:45:50 by aaleassa          #+#    #+#             */
/*   Updated: 2025/12/16 17:58:58 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nls;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		nls = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nls;
	}
	*lst = NULL;
}
