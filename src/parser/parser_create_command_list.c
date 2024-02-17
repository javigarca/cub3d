/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_create_command_list.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:16:05 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 17:58:17 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_commands	*first_command_create(int position);
static void			ft_add_command(t_commands *lst, int position);
static int			ft_first_priority_order(t_token *lst);
static void			ft_create_commands(t_token *lst, int position, \
													t_commands *commands_lst);

/**
 * Creates the commands list from the token list,
 * considering command grouping.
 * 
 * @param token_lst Pointer to the token list.
 * @return          Pointer to the head of the commands list.
 */
t_commands	*ft_ft_create_commands(t_token *token_lst)
{
	t_commands	*commands_lst;
	t_token		*lst;
	int			order_position;

	order_position = ft_first_priority_order(token_lst);
	lst = token_lst;
	commands_lst = first_command_create(order_position);
	if (commands_lst)
	{
		ft_create_commands(lst, order_position, commands_lst);
	}
	return (commands_lst);
}

/**
 * Creates the first command node in the commands list.
 * 
 * @param position Initial order position for the command.
 * @return         Pointer to the newly created command node.
 */
static t_commands	*first_command_create(int position)
{
	t_commands	*lst;

	lst = (t_commands *)malloc(sizeof(t_commands));
	if (!lst)
		return (NULL);
	lst->command_index = 0;
	lst->next = NULL;
	lst->order = position;
	lst->pipes = NULL;
	return (lst);
}

/**
 * Creates the commands list recursively from the token list.
 * 
 * @param lst       Pointer to the current token.
 * @param position  Current order position for the command.
 * @param commands  Pointer to the current commands list.
 */
static void	ft_create_commands(t_token *lst, int position, t_commands *commands)
{
	while (lst->type != LINE_END)
	{
		if (lst->type == NONE)
			lst = lst->next;
		if (lst)
		{
			if (lst->type == OPEN)
			{
				position++;
				lst = lst->next;
			}
			if (lst->type == CLOSE)
			{
				position--;
				lst = lst->next;
			}
			if (lst->type == SEMI || lst->type == ANDAND || lst->type == OR)
			{
				ft_add_command(commands, position);
				lst = lst->next;
			}
			else
				lst = ft_create_pipe_list(lst, commands);
		}
	}
}

/**
 * Adds a new command node to the commands list.
 * 
 * @param lst       Pointer to the current commands list.
 * @param position  Order position for the new command.
 */
static void	ft_add_command(t_commands *lst, int position)
{
	t_commands	*tmp;
	int			command_count;

	if (lst)
	{
		command_count = 1;
		tmp = lst;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
			command_count++;
		}
		tmp->next = (t_commands *)malloc(sizeof(t_commands));
		tmp->next->command_index = command_count;
		tmp->next->pipes = NULL;
		tmp->next->order = position;
		tmp->next->next = NULL;
	}
}

/**
 * Determines the initial order position for the commands list.
 * 
 * @param lst Pointer to the token list.
 * @return    Initial order position.
 */
static int	ft_first_priority_order(t_token *lst)
{
	t_token	*tmp;
	int		initial_order;

	initial_order = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->type == NONE)
			tmp = tmp->next;
		if (tmp->type == OPEN)
		{
			initial_order++;
			tmp = tmp->next;
		}
		else if (tmp->type == CLOSE)
		{
			initial_order--;
			tmp = tmp->next;
		}
		else
			break ;
	}
	return (initial_order);
}
