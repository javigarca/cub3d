/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:16:57 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 17:31:56 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	ft_type_to_string(t_token_type value);
static void	ft_type_to_string_cont(t_token_type value);

/**
 * Prints the debug information of a linked list of tokens.
 * 
 * @param lst Pointer to the head of the token list.
 */
void	ft_token_debug(t_token *lst)
{
	t_token	*tmp;

	tmp = lst;
	printf(KBLU);
	printf("\n ------------- TOKEN LIST DEBUG ------------- "KBLU);
	while (tmp)
	{
		printf("\n INDEX: %2d", tmp->index);
		printf("| TYPE: ");
		ft_type_to_string(tmp->type);
		printf("| VALUE: %20s", tmp->value);
		printf("| DIRE: %p", tmp->next);
		tmp = tmp->next;
	}
}

/**
 * Converts a token type enum value to its corresponding string
 * representation and prints it.
 * 
 * @param value Token type enum value to be converted and printed.
 */
static void	ft_type_to_string(t_token_type value)
{
	if (value == WORD)
		printf("%10s", "WORD");
	if (value == NONE)
		printf("%10s", "NONE");
	if (value == SEMI)
		printf("%10s", "SEMICOLON");
	if (value == GREAT)
		printf("%10s", "GREAT");
	if (value == LESS)
		printf("%10s", "LESS");
	if (value == PIPE)
		printf("%10s", "PIPE");
	ft_type_to_string_cont(value);
}

/**
 * Converts a token type enum value to its corresponding string 
 * representation and prints it (continued from ft_type_to_string).
 * 
 * @param value Token type enum value to be converted and printed.
 */
static void	ft_type_to_string_cont(t_token_type value)
{
	if (value == LINE_END)
		printf("%10s", "END");
	if (value == DOUBLE_GREAT)
		printf("%10s", "D_GREAT");
	if (value == DOUBLE_LESS)
		printf("%10s", "D_LESS");
	if (value == ANDAND)
		printf("%10s", "AND");
	if (value == OR)
		printf("%10s", "OR");
	if (value == OPEN)
		printf("%10s", "OPEN");
	if (value == CLOSE)
		printf("%10s", "CLOSE");
}
