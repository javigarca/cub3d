/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_syntax_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:02:23 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 17:02:42 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/**
 * Reports a syntax error to the user.
 * 
 * @param txt  Text containing information about the error.
 * @param type Type of syntax error (MULTILINES or UNEXPECTED).
 * @return     FALSE indicating a syntax error has occurred.
 */
int	ft_syntax_error(const char *txt, t_error_type type)
{
	ft_colorirze(1, KRED);
	ft_putstr_fd("minishell: ", 2);
	ft_colorirze(1, KNRM);
	if (type == MULTILINES)
		ft_putstr_fd("syntax error multiple line not allowed", 2);
	if (type == UNEXPECTED)
	{
		ft_putstr_fd("syntax error near unexpected token `", 2);
		ft_putstr_fd((char *)txt, 2);
		ft_putstr_fd("'", 2);
	}
	ft_putstr_fd("\n", 2);
	ft_error_w(2, 0);
	return (FALSE);
}
