/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_export_aux.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:40:26 by xamayuel          #+#    #+#             */
/*   Updated: 2022/05/31 16:44:11 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

void	sort_env_list(t_env *lst)
{
	char			*text_temp;
	t_env			*tmp;

	tmp = lst;
	while (lst->next != NULL)
	{
		if (ft_strncmp(lst->line, lst->next->line, MAXPROMPT) > 0)
		{
			text_temp = ft_strdup(lst->line);
			free(lst->line);
			lst->line = lst->next->line;
			lst->next->line = text_temp;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
}
