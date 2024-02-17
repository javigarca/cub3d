/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:47:39 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/13 11:32:18 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_lstdelone()
 * 
 * DESCRIPTION:
 * 		Delete element content and free an element using del function
 * 
 * PARAMS:
 * 		@param lst: element of the list
 * 		@param del: function to delete and free 
 * 
 * RETURN:
 * 		NOTHING
 */

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}
