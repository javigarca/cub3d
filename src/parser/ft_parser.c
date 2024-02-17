/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:07:03 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 18:04:27 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * Parses the token list and constructs a linked list of commands.
 * 
 * @param token_lst Pointer to the head of the token list.
 * @return          Pointer to the head of the commands list.
 */
t_commands	*ft_parser(t_token *token_lst)
{
	t_commands	*commands_lst;

	commands_lst = ft_ft_create_commands(token_lst);
	return (commands_lst);
}

/**
 * Converts a token type enum value to its corresponding
 * redirection type enum value.
 * 
 * @param type Token type enum value to be converted.
 * @return     Redirection type enum value.
 */
t_redirection_type	ft_convert_type(t_token_type type)
{
	if (type == GREAT)
		return (RE_GREAT);
	if (type == LESS)
		return (RE_LESS);
	if (type == DOUBLE_GREAT)
		return (RE_DOUBLE_GREAT);
	return (RE_DOUBLE_LESS);
}

/**
 * Checks if a token type corresponds to a redirection.
 * 
 * @param type Token type enum value to be checked.
 * @return     TRUE if the token type corresponds to a redirection,
 * 			   otherwise FALSE.
 */
int	ft_redir_type(t_token_type type)
{
	if (type == GREAT)
		return (TRUE);
	if (type == LESS)
		return (TRUE);
	if (type == DOUBLE_GREAT)
		return (TRUE);
	if (type == DOUBLE_LESS)
		return (TRUE);
	return (FALSE);
}

/**
 * Checks if a token type corresponds to a command.
 * 
 * @param type Token type enum value to be checked.
 * @return     TRUE if the token type corresponds to a command,
 * 			   otherwise FALSE.
 */
int	ft_command_type(t_token_type type)
{
	if (type == PIPE)
		return (TRUE);
	if (type == SEMI)
		return (TRUE);
	if (type == ANDAND)
		return (TRUE);
	if (type == OR)
		return (TRUE);
	if (type == LINE_END)
		return (TRUE);
	return (FALSE);
}
