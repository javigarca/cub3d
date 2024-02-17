/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free_memory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:56:51 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 18:03:30 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	free_pipe_list_memory(t_pipes *lst);
static void	free_cmd_list_memory(t_cmd *lst);
static void	free_args_list_memory(t_args *lst);
static void	free_redir_list_memory(t_redirections *lst);

/**
 * Frees the memory allocated for the commands list.
 * 
 * @param lst Pointer to the first node of the commands list.
 */
void	ft_free_command_list_memory(t_commands *lst)
{
	t_commands	*aux;

	aux = NULL;
	if (lst)
	{
		while (lst->next != NULL)
		{
			aux = lst;
			lst = lst->next;
			free_pipe_list_memory(aux->pipes);
			free(aux);
		}
		free_pipe_list_memory(lst->pipes);
		free(lst);
	}
}

/**
 * Frees the memory allocated for the pipe list.
 * 
 * @param lst Pointer to the first node of the pipe list.
 */
static void	free_pipe_list_memory(t_pipes *lst)
{
	t_pipes	*aux;

	if (lst)
	{
		aux = NULL;
		while (lst->next != NULL)
		{
			aux = lst;
			lst = lst->next;
			free(aux->command);
			free_cmd_list_memory(aux->cmd);
			free(aux);
		}
		free(lst->command);
		free_cmd_list_memory(lst->cmd);
		free(lst);
	}
}

/**
 * Frees the memory allocated for the command list.
 * 
 * @param lst Pointer to the first node of the command list.
 */
static void	free_cmd_list_memory(t_cmd *lst)
{
	if (lst)
	{
		free(lst->command);
		free_args_list_memory(lst->args);
		free_redir_list_memory(lst->redirections);
		free(lst);
	}
}

/**
 * Frees the memory allocated for the arguments list.
 * 
 * @param lst Pointer to the first node of the arguments list.
 */
static void	free_args_list_memory(t_args *lst)
{
	t_args	*aux;

	aux = NULL;
	while (lst->next != NULL)
	{
		aux = lst;
		lst = lst->next;
		free(aux->value);
		free(aux);
	}
	free(lst->value);
	free(lst);
}

/**
 * Frees the memory allocated for the redirections list.
 * 
 * @param lst Pointer to the first node of the redirections list.
 */
static void	free_redir_list_memory(t_redirections *lst)
{
	t_redirections	*aux;

	aux = NULL;
	while (lst->next != NULL)
	{
		aux = lst;
		lst = lst->next;
		free(aux->filename);
		free(aux);
	}
	free(lst->filename);
	free(lst);
}
