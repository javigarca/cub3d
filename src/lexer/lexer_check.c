/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:34:18 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 17:33:12 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/**
 * Checks the validity of parenthesis in the token list.
 * 
 * @param lst Pointer to the head of the token list.
 * @return    TRUE if the parenthesis are balanced,
 * 			  otherwise returns FALSE and reports a syntax error.
 */
static int	ft_check_parenthesis(t_token *lst)
{
	t_token	*tmp;
	int		cont;

	tmp = lst;
	cont = 0;
	while (tmp->type != LINE_END)
	{
		if (tmp->type == OPEN)
			cont++;
		if (tmp->type == CLOSE)
			cont--;
		if (cont < 0)
			return (ft_syntax_error(")", UNEXPECTED));
		tmp = tmp->next;
	}
	if (cont == 0)
		return (TRUE);
	else
		return (ft_syntax_error("", MULTILINES));
}

/**
 * Checks the validity of the syntax in the token list.
 * 
 * @param lst Pointer to the head of the token list.
 * @return    TRUE if the syntax is valid,
 * 			  otherwise returns FALSE and reports a syntax error.
 */
int	ft_syntaxis_is_valid(t_token *lst)
{
	t_token	*tmp;
	int		valid;

	tmp = lst;
	valid = ft_check_parenthesis(tmp);
	if (valid == TRUE)
	{
		while (tmp->type != LINE_END)
		{
			if (tmp->type == WORD && tmp->next->type == LINE_END)
			{
				valid = ft_last_word_is_valid(lst, tmp);
				if (valid == FALSE)
					break ;
			}
			else
			{
				valid = ft_word_is_valid(lst, tmp);
				if (valid == FALSE)
					break ;
			}
			tmp = tmp->next;
		}
	}
	return (valid);
}
