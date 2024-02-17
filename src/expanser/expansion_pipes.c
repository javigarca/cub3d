/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 21:03:03 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 19:07:46 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expanser.h"

void	ft_expansion_pipes(t_pipes *lst, t_env *env)
{
	t_pipes	*tmp;

	if (lst)
	{
		tmp = lst;
		while (tmp->next != NULL)
		{
			ft_expansion_cmd(tmp->cmd, env);
			tmp = tmp->next;
		}
		ft_expansion_cmd(tmp->cmd, env);
	}
}
