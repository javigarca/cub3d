/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:31:08 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/13 10:49:49 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_lstadd_front()
 * 
 * DESCRIPTION:
 * 		Add new element to the begining of the list.
 * 
 * RETURN:
 * 		NOTHING.
 * 
 * PARAMS:
 * 		@param lst: list of pointers
 * 		@param new: new element of the list.
 *
 * TIPS:
 * 		1. - New next to lst
 * 		2 -  LST point to new
 */

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
