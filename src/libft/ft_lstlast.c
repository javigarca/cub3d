/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:38:26 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/13 11:32:19 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_lstlast()
 * 
 * DESCRIPTION:
 * 		Return the last element of the list lst		
 * 
 * PARAMS:
 * 		@param lst: list
 * 
 * RETURN:
 *		The last value of the list.
 * 
 */

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
		{
			lst = lst->next;
		}
	}
	return (lst);
}
