/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expansion_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:59:00 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 13:29:02 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expanser.h"

/**
 * @brief 
 * 
 * @param lst 
 */
void	ft_expansion_args(t_args *lst, t_env *env)
{
	t_args	*tmp;

	if (lst)
	{
		(void)env;
		tmp = lst;
		while (tmp)
		{
			if (tmp->arg_index > 0)
			{
				tmp->value = ft_expand_quotes_dollar(tmp->value, env);
				if (ft_strlen(tmp->value) == 0 && tmp->next != NULL)
				{
					ft_strlcpy(tmp->value, tmp->next->value, \
								ft_strlen(tmp->next->value) + 1);
					tmp->next = tmp->next->next;
				}
				if (ft_strlen(tmp->value) == 0 && tmp->next == NULL)
				{
					lst->next = NULL;
				}
			}
			tmp = tmp->next;
		}
	}
}
