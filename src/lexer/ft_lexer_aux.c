/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:24:00 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 17:23:05 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/**
 * Evaluates the presence of the greater-than symbol ('>') in the input line
 * and adds the corresponding token to the token list.
 * 
 * @param lst  Pointer to the token list.
 * @param line Pointer to the input line.
 * @param i    Current index in the input line.
 * @return     Updated index after processing.
 */
int	ft_evaluate_greater(t_token *lst, char *line, int i)
{
	if (line[i + 1] == '>')
		ft_add_token(lst, DOUBLE_GREAT, ">>", 1 + i++);
	else
		ft_add_token(lst, GREAT, ">", i + 1);
	return (i);
}

/**
 * Evaluates the presence of the less-than symbol ('<') in the input line 
 * and adds the corresponding token to the token list.
 * 
 * @param lst  Pointer to the token list.
 * @param line Pointer to the input line.
 * @param i    Current index in the input line.
 * @return     Updated index after processing.
 */
int	ft_evaluate_less(t_token *lst, char *line, int i)
{
	if (line[i + 1] == '<')
		ft_add_token(lst, DOUBLE_LESS, "<<", 1 + i++);
	else
		ft_add_token(lst, LESS, "<", i + 1);
	return (i);
}

/**
 * Processes the input line and adds tokens to the token list based 
 * on certain characters.
 * 
 * @param lst  Pointer to the token list.
 * @param line Pointer to the input line.
 * @return     Total number of tokens processed.
 */
int	ft_do_tokens(t_token *lst, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '(' && !ft_open_quotes(line, i))
			ft_add_token(lst, OPEN, "(", 1 + i);
		if (line[i] == ')' && !ft_open_quotes(line, i))
			ft_add_token(lst, CLOSE, ")", 1 + i);
		if (line[i] == '|' && line[i + 1] == '|' && !ft_open_quotes(line, i))
			ft_add_token(lst, OR, "||", 1 + i++);
		if (line[i] == '|' && line[i + 1] != '|' && !ft_open_quotes(line, i))
			ft_add_token(lst, PIPE, "|", i + 1);
		if (line[i] == '>' && !ft_open_quotes(line, i))
			i = ft_evaluate_greater(lst, line, i);
		if (line[i] == '<' && !ft_open_quotes(line, i))
			i = ft_evaluate_less(lst, line, i);
		if (line[i] == ';' && !ft_open_quotes(line, i))
			ft_add_token(lst, SEMI, ";", i + 1);
		if (line[i] == '&' && line[i + 1] == '&' && !ft_open_quotes(line, i))
			ft_add_token(lst, ANDAND, "&&", 1 + i++);
		i++;
	}
	return (i);
}
