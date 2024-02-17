/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:42:13 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/13 10:48:59 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_lstadd_back()
 * 
 * DESCRIPTION:
 * 		Adds new element to the end of the list.
 * 
 * RETURN:
 * 		NOTHING.
 * 
 * PARAMS:
 * 		@param lst: list of pointers
 * 		@param new: new element of the list.
 * 
 * TIPS:
 * 		1. - IF LST IS NULL, LST = NEW
 * 		2. - USE FS_LSTLAST and next to new
 */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if ((*lst) == NULL)
		(*lst) = new;
	else
	{
		ft_lstlast(*lst)->next = new;
	}
}
