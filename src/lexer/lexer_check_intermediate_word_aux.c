/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check_intermediate_word_aux.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:54:21 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 17:26:04 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/**
 * Checks if the token following an open parenthesis '(' is valid.
 * 
 * @param tmp Pointer to the token representing the open parenthesis.
 * @return    TRUE if the following token is valid,
 * 			  otherwise returns FALSE and reports a syntax error.
 */
int	ft_open_is_valid(t_token *tmp)
{
	if (tmp->next->type == CLOSE)
		return (ft_syntax_error("(", UNEXPECTED));
	if (tmp->next->type == SEMI)
		return (ft_syntax_error("(", UNEXPECTED));
	if (tmp->next->type == PIPE)
		return (ft_syntax_error("|", UNEXPECTED));
	if (tmp->next->type == ANDAND)
		return (ft_syntax_error("&&", UNEXPECTED));
	if (tmp->next->type == OR)
		return (ft_syntax_error("||", UNEXPECTED));
	return (TRUE);
}

/**
 * Checks if the token following a close parenthesis ')' is valid.
 * 
 * @param tmp Pointer to the token representing the close parenthesis.
 * @return    TRUE if the following token is valid,
 * 			  otherwise returns FALSE and reports a syntax error.
 */
int	ft_close_is_valid(t_token *tmp)
{
	if (tmp->next->type == OPEN)
		return (ft_syntax_error(")", UNEXPECTED));
	if (tmp->next->type == WORD)
		return (ft_syntax_error(tmp->next->value, UNEXPECTED));
	return (TRUE);
}

/**
 * Checks if the token following a logical OR '||' is valid.
 * 
 * @param tmp Pointer to the token representing the logical OR.
 * @return    TRUE if the following token is valid,
 * 			  otherwise returns FALSE and reports a syntax error.
 */
int	ft_or_is_valid(t_token *tmp)
{
	if (tmp->next->type == LINE_END)
		return (ft_syntax_error("", MULTILINES));
	if (tmp->next->type == PIPE)
		return (ft_syntax_error("|", UNEXPECTED));
	if (tmp->next->type == SEMI)
		return (ft_syntax_error(";", UNEXPECTED));
	if (tmp->next->type == ANDAND)
		return (ft_syntax_error("&&", UNEXPECTED));
	if (tmp->next->type == OR)
		return (ft_syntax_error("||", UNEXPECTED));
	return (TRUE);
}

/**
 * Checks if the token following a logical AND '&&' is valid.
 * 
 * @param tmp Pointer to the token representing the logical AND.
 * @return    TRUE if the following token is valid,
 * 			  otherwise returns FALSE and reports a syntax error.
 */
int	ft_and_is_valid(t_token *tmp)
{
	if (tmp->next->type == LINE_END)
		return (ft_syntax_error("", MULTILINES));
	if (tmp->next->type == PIPE)
		return (ft_syntax_error("|", UNEXPECTED));
	if (tmp->next->type == SEMI)
		return (ft_syntax_error(";", UNEXPECTED));
	if (tmp->next->type == ANDAND)
		return (ft_syntax_error("&&", UNEXPECTED));
	if (tmp->next->type == OR)
		return (ft_syntax_error("||", UNEXPECTED));
	return (TRUE);
}
