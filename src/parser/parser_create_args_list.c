/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_create_args_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 22:13:09 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 17:54:46 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * Adds a new argument to the arguments list.
 * 
 * @param args  Pointer to the head of the arguments list.
 * @param value Value of the argument to be added.
 */
void	ft_add_args(t_args *args, char *value)
{
	t_args		*tmp;
	int			arg_count;

	arg_count = 1;
	tmp = args;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		arg_count++;
	}
	tmp->next = (t_args *)malloc(sizeof(t_args));
	tmp->next->arg_index = arg_count;
	tmp->next->value = ft_strdup(value);
	tmp->next->next = NULL;
}
