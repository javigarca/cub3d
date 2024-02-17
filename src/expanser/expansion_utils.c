/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:04:43 by xamayuel          #+#    #+#             */
/*   Updated: 2022/06/01 15:11:01 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expanser.h"

/**
 * @brief: Function to return the maximum enviroment length 
 * 
 * @param env : enviroment arguments
 * 
 * @return int : maximum length in enviroments arguments
 */
int	ft_ft_max_env_arg_size(t_env *env)
{
	size_t	max;
	t_env	*tmp;

	tmp = env;
	max = 0;
	while (tmp)
	{
		if (max < ft_strlen(tmp->line))
			max = ft_strlen(tmp->line);
		tmp = tmp->next;
	}
	return (max);
}

int	ft_change_quote(int *quotes)
{
	*quotes = (*quotes) * (-1);
	return (1);
}
