/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expansion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 12:45:23 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 19:07:46 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expanser.h"

/**
 * @brief: Function that go through the command list and 
 * 		   launch the pipe expansion function.
 * 
 * @param lst : command list.
 * @param env : enviroment variables.
 * 
 * @return t_commands* : t_command list after expansion
 */
t_commands	*ft_expansion(t_commands *lst, t_env *env)
{
	t_commands	*tmp;

	ft_delete_heredoc_files();
	if (lst)
	{
		tmp = lst;
		while (tmp->next != NULL)
		{
			ft_expansion_pipes(tmp->pipes, env);
			tmp = tmp->next;
		}
		ft_expansion_pipes(tmp->pipes, env);
	}
	return (lst);
}
