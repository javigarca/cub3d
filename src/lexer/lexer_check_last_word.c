/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check_last_word.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:39:32 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 17:32:40 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/**
 * Checks if the last word token in the token list is valid,
 * considering the presence of open quotes and backslashes.
 * 
 * @param lst Pointer to the head of the token list.
 * @param tmp Pointer to the last word token to be validated.
 * @return    TRUE if the last word token is valid,
 * 			  otherwise returns FALSE and reports a syntax error.
 */
int	ft_last_word_is_valid(t_token *lst, t_token *tmp)
{
	int	valid;

	valid = TRUE;
	if (ft_open_quotes(tmp->value, ft_strlen(tmp->value)) != FALSE)
		valid = ft_syntax_error("", MULTILINES);
	if (ft_count_backslash(tmp->value, ft_strlen(tmp->value)) % 2 != 0)
		valid = ft_syntax_error("", MULTILINES);
	(void)lst;
	return (valid);
}
