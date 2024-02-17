/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_free_memory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:56:51 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 17:30:06 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/**
 * Frees the memory allocated for a linked list of tokens.
 * 
 * @param lst Pointer to the head of the token list.
 */
void	ft_free_token_list(t_token *lst)
{
	t_token	*aux;

	aux = NULL;
	while (lst->type != LINE_END)
	{
		aux = lst;
		lst = lst->next;
		free(aux->value);
		free(aux);
	}
	if (lst->type == LINE_END)
	{
		free(lst->value);
		free(lst);
	}
}
