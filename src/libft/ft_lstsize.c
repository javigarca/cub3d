/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:34:12 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/13 10:58:58 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_lstsize()
 * 
 * DESCRIPTION:
 * 		Return the size of a list.
 * 
 * RETURN:
 * 		Size of the list.
 * 
 * PARAMS:
 * 		@param lst: list
 * 
 * TIPS:
 * 		1. If lst exits, then min size = 1.
 */

int	ft_lstsize(t_list *lst)
{
	size_t	size;

	size = 0;
	if (lst)
	{
		size = 1;
		while (lst->next != NULL)
		{
			lst = lst->next;
			size++;
		}
	}
	return (size);
}
