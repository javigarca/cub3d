/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:19:51 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/13 11:32:20 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_lstnew()
 * 
 * DESCRIPTION:
 * 		Allocates with malloc and return fresh link.
 * 		New element content equal to content.
 * 		New element next equal to NULL
 * 
 * PARAMS:
 * 		@param	content: content of the first element of the list
 * 
 * RETURN:
 *		New fresh element.
 * 
 */

t_list	*ft_lstnew(void *content)
{
	t_list	*output;

	output = (t_list *)malloc (sizeof(t_list));
	if (output != NULL)
	{
		output->content = content;
		output->next = NULL;
	}
	return (output);
}
