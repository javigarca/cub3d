/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check_intermediate_word.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:43:30 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 17:28:20 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	ft_redirection_is_valid(t_token *tmp);
static int	ft_pipe_is_valid(t_token *tmp);
static int	ft_semi_is_valid(t_token *tmp);
static int	ft_intermediate_word_is_valid(t_token *lst, t_token *tmp);

/**
 * Checks if the token represents a valid word based on its type
 * and following tokens.
 * 
 * @param lst Pointer to the head of the token list.
 * @param tmp Pointer to the token to be validated.
 * @return    TRUE if the token is valid, otherwise returns FALSE
 * 			  and reports a syntax error.
 */
int	ft_word_is_valid(t_token *lst, t_token *tmp)
{
	int	valid;

	valid = TRUE;
	if (tmp->type == NONE)
		valid = ft_first_ft_word_is_valid(tmp);
	if (tmp->type == GREAT || tmp->type == DOUBLE_GREAT \
							|| tmp->type == LESS || tmp->type == DOUBLE_LESS)
		valid = ft_redirection_is_valid(tmp);
	if (tmp->type == PIPE)
		valid = ft_pipe_is_valid(tmp);
	if (tmp->type == OR)
		valid = ft_or_is_valid(tmp);
	if (tmp->type == ANDAND)
		valid = ft_and_is_valid(tmp);
	if (tmp->type == SEMI)
		valid = ft_semi_is_valid(tmp);
	if (tmp->type == WORD)
		valid = ft_intermediate_word_is_valid(lst, tmp);
	if (tmp->type == OPEN)
		valid = ft_open_is_valid(tmp);
	if (tmp->type == CLOSE)
		valid = ft_close_is_valid(tmp);
	(void)lst;
	return (valid);
}

/**
 * Checks if the redirection token and its following token are valid.
 * 
 * @param tmp Pointer to the redirection token.
 * @return    TRUE if the redirection is valid,
 * 			  otherwise returns FALSE and reports a syntax error.
 */
static int	ft_redirection_is_valid(t_token *tmp)
{
	if (tmp->next->type == PIPE)
		return (ft_syntax_error("|", UNEXPECTED));
	if (tmp->next->type == SEMI)
		return (ft_syntax_error(";", UNEXPECTED));
	if (tmp->next->type != WORD)
	{
		if (tmp->type == GREAT)
			return (ft_syntax_error(">", UNEXPECTED));
		else
			return (ft_syntax_error("<", UNEXPECTED));
	}
	return (TRUE);
}

/**
 * Checks if the pipe token and its following token are valid.
 * 
 * @param tmp Pointer to the pipe token.
 * @return    TRUE if the pipe is valid,
 * 			  otherwise returns FALSE and reports a syntax error.
 */
static int	ft_pipe_is_valid(t_token *tmp)
{
	if (tmp->next->type == LINE_END)
		return (ft_syntax_error("", MULTILINES));
	if (tmp->next->type == PIPE)
		return (ft_syntax_error("|", UNEXPECTED));
	if (tmp->next->type == SEMI)
		return (ft_syntax_error(";", UNEXPECTED));
	return (TRUE);
}

/**
 * Checks if the semicolon token and its following token are valid.
 * 
 * @param tmp Pointer to the semicolon token.
 * @return    TRUE if the semicolon is valid,
 * 			  otherwise returns FALSE and reports a syntax error.
 */
static int	ft_semi_is_valid(t_token *tmp)
{
	if (tmp->next->type == PIPE)
		return (ft_syntax_error("|", UNEXPECTED));
	if (tmp->next->type == SEMI)
		return (ft_syntax_error(";", UNEXPECTED));
	return (TRUE);
}

/**
 * Checks if an intermediate word token is valid,
 * considering the presence of open quotes.
 * 
 * @param lst Pointer to the head of the token list.
 * @param tmp Pointer to the intermediate word token.
 * @return    TRUE if the intermediate word is valid,
 * 			  otherwise returns FALSE and reports a syntax error.
 */
static int	ft_intermediate_word_is_valid(t_token *lst, t_token *tmp)
{
	int	valid;

	valid = TRUE;
	if (ft_open_quotes(tmp->value, ft_strlen(tmp->value)) != FALSE)
		valid = ft_syntax_error("", MULTILINES);
	(void)lst;
	return (valid);
}
