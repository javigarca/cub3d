/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_debug.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:16:57 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 18:02:31 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ELIMINAR ANTES DE ENTREGAR. CONTIENE FUNCIONES NO PERMITIDAS fflush
#include "parser.h"

static void	ft_pipe_list_debug(t_pipes *lst);
static void	ft_cmd_list_debug(t_cmd *lst);
static void	ft_args_list_debug(t_args *lst);
static void	ft_redir_list_debug(t_redirections *lst);

/**
 * Prints the debug information for the commands list.
 * 
 * @param lst Pointer to the first node of the commands list.
 */
void	ft_commands_list_debug(t_commands *lst)
{
	t_commands	*tmp;

	if (lst)
	{
		tmp = lst;
		printf("\n ------------- COMMAND LIST DEBUG ------------- "KBLU);
		printf(KRED);
		while (tmp != NULL)
		{
			printf(KRED);
			printf("\n\n COMMAND INDEX:%2d", tmp->command_index);
			printf("| DIRECTION: %14p", tmp);
			printf("|  NEXT: %60p", tmp->next);
			printf("| PIPEX DIRECTION: %2p", tmp->pipes);
			printf("|ORDER: %d", tmp->order);
			ft_pipe_list_debug(tmp->pipes);
			tmp = tmp->next;
		}
		printf(KRED"\n\n Output \n");
		printf(KNON);
	}
}

/**
 * Prints the debug information for the pipe list.
 * 
 * @param lst Pointer to the first node of the pipe list.
 */
static void	ft_pipe_list_debug(t_pipes *lst)
{
	t_pipes	*tmp;

	if (lst)
	{
		tmp = lst;
		printf(KMAG);
		while (tmp != NULL)
		{
			printf(KMAG);
			printf("\n ┕┅┅PIPE INDEX:%2d", tmp->pipes_index);
			printf("| DIRECTION: %2p", tmp);
			printf("|  NEXT: %60p", tmp->next);
			printf("|   CMD DIRECTION: %2p", tmp->cmd);
			ft_cmd_list_debug(tmp->cmd);
			tmp = tmp->next;
		}
	}
}

/**
 * Prints the debug information for the command list.
 * 
 * @param lst Pointer to the first node of the command list.
 */
static void	ft_cmd_list_debug(t_cmd *lst)
{
	t_cmd	*tmp;

	printf(KGRN);
	if (lst)
	{
		tmp = lst;
		printf("\n   ┕┅CMD INDEX:%2d| DIRECTION: %14p", tmp->cmd_index, tmp);
		printf("| VALUE: %60s", tmp->command);
		printf("|        BUILT_IN: %d", lst->is_builtin);
		ft_args_list_debug(lst->args);
		ft_redir_list_debug(lst->redirections);
	}
}

/**
 * Prints the debug information for the arguments list.
 * 
 * @param lst Pointer to the first node of the arguments list.
 */
static void	ft_args_list_debug(t_args *lst)
{
	t_args	*tmp;

	if (lst)
	{
		printf(KBLU);
		tmp = lst;
		while (tmp != NULL)
		{
			printf("\n    ┕ARG INDEX:%2d", tmp->arg_index);
			printf("| DIRECTION: %2p", tmp);
			printf("| VALUE: %60s", tmp->value);
			printf("|        ARG NEXT: %14p", tmp->next);
			tmp = tmp->next;
		}
	}
}

/**
 * Prints the debug information for the redirections list.
 * 
 * @param lst Pointer to the first node of the redirections list.
 */
static void	ft_redir_list_debug(t_redirections *lst)
{
	t_redirections	*tmp;

	if (lst)
	{
		printf(KYEL);
		tmp = lst;
		while (tmp != NULL)
		{
			printf("\n    ┕┅RE INDEX:%2d", tmp->redirection_index);
			printf("| DIRECTION: %2p", tmp);
			printf("| FILENAME: %57s", tmp->filename);
			printf("|            TYPE: %2d", tmp->type);
			tmp = tmp->next;
		}
	}
}
