/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:24:28 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 17:16:44 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	ft_swap_int(int *a, int *b);

/**
 * Sorts a linked list of tokens in ascending order based on their index.
 * 
 * @param lst Pointer to the head of the token list.
 * @return    Pointer to the head of the sorted token list.
 */
t_token	*ft_sort_token(t_token *lst)
{
	t_token_type	type_temp;
	char			*text_temp;
	t_token			*tmp;

	tmp = lst;
	while (lst->next != NULL)
	{
		if (lst->index > lst->next->index)
		{
			ft_swap_int(&lst->index, &lst->next->index);
			type_temp = lst->type;
			lst->type = lst->next->type;
			lst->next->type = type_temp;
			text_temp = ft_strdup(lst->value);
			free(lst->value);
			lst->value = lst->next->value;
			lst->next->value = text_temp;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}

/**
 * Swaps the values of two integers.
 * 
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 */
void	ft_swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
