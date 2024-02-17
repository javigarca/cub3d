/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check_first_word.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:46:19 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 17:24:24 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/**
 * Checks if the first word in the token list is valid based on 
 * its following token type.
 * 
 * @param tmp Pointer to the first token in the token list.
 * @return    TRUE if the first word is valid, otherwise returns FALSE
 * 			  and reports a syntax error.
 */
int	ft_first_ft_word_is_valid(t_token *tmp)
{
	if (tmp->next)
	{
		if (tmp->next->type == PIPE)
			return (ft_syntax_error("|", UNEXPECTED));
		if (tmp->next->type == SEMI)
			return (ft_syntax_error(";", UNEXPECTED));
	}
	return (TRUE);
}
