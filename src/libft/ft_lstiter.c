/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:57:32 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/13 11:32:18 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_lstiter()
 * 
 * DESCRIPTION:
 * 		Iterates the list lst and applies the function f to each link.
 * 
 * RETURN:
 * 		NOTHING
 * 	
 * PARAMS:
 * 		@param	lst: element of the list
 * 		@param 	  f: functon to be applied.
 * 
 * TIPS:
 * 		1. - Don't forget the last element of the list!
 */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst)
	{
		while (lst->next != NULL)
		{
			f(lst->content);
			lst = lst->next;
		}
		f(lst->content);
	}
}
