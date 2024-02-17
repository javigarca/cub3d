/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_create_redir_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 22:13:09 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 18:00:34 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * Adds a new redirection node to the redirections list.
 * 
 * @param redir Pointer to the redirections list.
 * @param value The filename or path for the redirection.
 * @param type  The type of redirection (e.g., RE_GREAT, RE_LESS, etc.).
 */
void	ft_add_redirection(t_redirections *redir, char *value, \
						t_redirection_type type)
{
	t_redirections	*tmp;
	int				redir_count;

	redir_count = 1;
	tmp = redir;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		redir_count++;
	}
	tmp->next = (t_redirections *)malloc(sizeof(t_redirections));
	tmp->next->redirection_index = redir_count;
	tmp->next->type = type;
	tmp->next->filename = ft_strdup(value);
	tmp->next->next = NULL;
}
