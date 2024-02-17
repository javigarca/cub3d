/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_create_pipe_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:22:25 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 17:59:55 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_pipes	*ft_first_pipe_create(void);
static void		ft_add_pipe(t_pipes *pipe_lst, t_token *token_lst);

/**
 * Creates the pipes list for a command in the commands list.
 * 
 * @param lst           Pointer to the token list.
 * @param commands_lst  Pointer to the current commands list.
 * @return              Pointer to the next token after processing the list.
 */
t_token	*ft_create_pipe_list(t_token *lst, t_commands *commands_lst)
{
	while (commands_lst->next != NULL)
		commands_lst = commands_lst->next;
	commands_lst->pipes = ft_first_pipe_create();
	while (lst->next != NULL)
	{
		if (lst->type == PIPE)
			ft_add_pipe(commands_lst->pipes, lst);
		else
			lst = ft_create_cmd_list(lst, commands_lst->pipes);
		if (lst->next->type == SEMI || lst->next->type == ANDAND)
			return (lst->next);
		if (lst->next->type == OR)
			return (lst->next);
		if (lst->next->type == LINE_END)
			return (lst->next);
		lst = lst->next;
	}
	return (lst);
}

/**
 * Adds a new pipe node to the pipes list of a command.
 * 
 * @param pipe_lst   Pointer to the pipes list of a command.
 * @param token_lst  Pointer to the current token representing the pipe.
 */
static void	ft_add_pipe(t_pipes *pipe_lst, t_token *token_lst)
{
	t_pipes		*tmp;
	int			pipe_count;

	pipe_count = 1;
	tmp = pipe_lst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		pipe_count++;
	}
	tmp->next = (t_pipes *)malloc(sizeof(t_pipes));
	tmp->next->pipes_index = pipe_count;
	tmp->next->cmd = NULL;
	tmp->next->command = ft_strdup(token_lst->next->value);
	tmp->next->next = NULL;
}

/**
 * Creates the first pipe node in the pipes list.
 * 
 * @return  Pointer to the newly created pipe node.
 */
static t_pipes	*ft_first_pipe_create(void)
{
	t_pipes	*lst;

	lst = (t_pipes *)malloc(sizeof(t_pipes));
	if (!lst)
		return (NULL);
	lst->pipes_index = 0;
	lst->next = NULL;
	lst->cmd = NULL;
	lst->command = ft_strdup("NONE");
	return (lst);
}
