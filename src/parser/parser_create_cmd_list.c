/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_create_cmd_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:05:26 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 18:04:27 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_args			*ft_first_args_create(void);
static t_redirections	*ft_first_redirection_create(void);
static void				ft_add_word(int *is_cmd, t_pipes	*tmp, t_token *lst);

/**
 * Creates the first command node in the command list.
 * 
 * @return Pointer to the newly created command node.
 */
t_cmd	*first_cmd_create(void)
{
	t_cmd	*lst;

	lst = (t_cmd *)malloc(sizeof(t_cmd));
	if (!lst)
		return (NULL);
	lst->cmd_index = 0;
	lst->command = NULL;
	lst->is_builtin = FALSE;
	lst->args = ft_first_args_create();
	lst->redirections = ft_first_redirection_create();
	return (lst);
}

/**
 * Creates the command list from the token list,
 * populating command nodes with arguments and redirections.
 * 
 * @param lst       Pointer to the token list.
 * @param pipes_lst Pointer to the pipes list.
 * @return          Pointer to the next token
 * 				    after processing the command list.
 */
t_token	*ft_create_cmd_list(t_token *lst, t_pipes *pipes_lst)
{
	int		is_cmd;
	t_pipes	*tmp;

	tmp = pipes_lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	is_cmd = FALSE;
	tmp->cmd = first_cmd_create();
	while (lst)
	{
		if (lst->type == WORD)
		{
			ft_add_word(&is_cmd, tmp, lst);
		}
		if (ft_redir_type(lst->type) == TRUE)
		{
			ft_add_redirection(tmp->cmd->redirections, lst->next->value, \
			ft_convert_type(lst->type));
			lst = lst->next;
		}
		if (ft_command_type(lst->next->type) == TRUE)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

/**
 * Creates the first node in the arguments list.
 * 
 * @return Pointer to the newly created arguments node.
 */
static t_args	*ft_first_args_create(void)
{
	t_args	*lst;

	lst = (t_args *)malloc(sizeof(t_args));
	if (!lst)
		return (NULL);
	lst->arg_index = 0;
	lst->next = NULL;
	lst->value = ft_strdup("NONE");
	return (lst);
}

/**
 * Creates the first node in the redirections list.
 * 
 * @return Pointer to the newly created redirections node.
 */
static t_redirections	*ft_first_redirection_create(void)
{
	t_redirections	*lst;

	lst = (t_redirections *)malloc(sizeof(t_redirections));
	if (!lst)
		return (NULL);
	lst->filename = ft_strdup("NONE");
	lst->next = NULL;
	lst->redirection_index = 0;
	lst->type = RE_GREAT;
	return (lst);
}

/**
 * Adds a word token to the command node or an argument to the arguments list.
 * 
 * @param is_cmd Indicator to determine if it's the first word in the command.
 * @param tmp    Pointer to the current pipes node.
 * @param lst    Pointer to the current token.
 */
static void	ft_add_word(int *is_cmd, t_pipes	*tmp, t_token *lst)
{
	if (*is_cmd == FALSE)
	{
		tmp->cmd->command = ft_strdup(lst->value);
		*is_cmd = TRUE;
	}
	else
		ft_add_args(tmp->cmd->args, lst->value);
}
