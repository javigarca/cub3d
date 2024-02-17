/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:51:16 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/13 11:32:17 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_lstclear()
 * 
 * DESCRIPTION:
 * 		Delete and free each element in the list lst, using del function 
 * 
 * RETURN:
 * 		Nothing
 * 
 * PARAMS:
 * 		@param lst: pointer of the list
 * 		@param del: function to delete and free a list element.
 * 
 * TIP:	
 * 		1. - Use ft_lstdelone in each element.
 */

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;

	if (*lst)
	{
		while ((*lst) != NULL)
		{
			aux = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = aux;
		}
	}
}
