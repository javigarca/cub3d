/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:57:32 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/13 11:28:34 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_lstmap()
 * 
 * DESCRIPTION:
 * 		Iterates a list and applies the function f to each link to create 
 * 		a fresh list. If allocations fails returns NULL.
 * 
 * RETURN:
 * 		The new list.
 * 
 * PARAMAS:
 * 		@param lst: list
 * 		@param f: function to be applied
 * 		@param del: funciont to delete and free a list element
 * 
 * TIPS:
 * 		1. - lst_out first set to (void*)0
 * 		2. - create aux lst with only 1 chain by means ft_lstnew(f())
 * 		3. - Protect ft_lstnew
 * 		4. - Add back by ft_lstadd_back
 */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new_out;

	if (!lst)
		return (NULL);
	new_out = (void *)0;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&new_out, del);
			return (NULL);
		}
		ft_lstadd_back(&new_out, new);
		lst = lst->next;
	}
	return (new_out);
}
