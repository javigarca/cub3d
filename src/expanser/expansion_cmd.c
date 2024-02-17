/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 21:04:35 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 11:07:14 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expanser.h"

int	count_args(t_args *args)
{
	int		count;
	t_args	*tmp;

	count = 0;
	tmp = args;
	while (tmp->next != NULL)
	{
		count ++;
		tmp = tmp->next;
	}
	return (count);
}

void	ft_expand_cmd_and_args(t_cmd *tmp, t_env *env)
{
	ft_expansion_cmd_bin(tmp, env);
	ft_expansion_args(tmp->args, env);
}

void	ft_expansion_cmd(t_cmd *lst, t_env *env)
{
	t_cmd	*tmp;
	t_args	*f;

	if (!lst)
		return ;
	tmp = lst;
	if (tmp->command != NULL)
	{
		tmp->command = ft_expand_quotes_dollar(tmp->command, env);
		if (ft_strlen(tmp->command) == 0)
		{
			if (tmp->args != NULL && tmp->args->next != NULL)
			{
				f = tmp->args->next;
				ft_strlcpy(tmp->command, f->value, ft_strlen(f->value) + 1);
				tmp->args->next = f->next;
				free(f);
			}
			else
				return ;
		}
		ft_expand_cmd_and_args(tmp, env);
	}
	ft_expansion_redir(tmp->redirections, env);
}

void	expansion_cmd2(t_cmd *lst, t_env *env)
{
	t_cmd	*tmp;
	int		i;

	i = 0;
	if (lst)
	{
		tmp = lst;
		if (tmp->command != NULL)
		{
			tmp->command = ft_expand_quotes_dollar(tmp->command, env);
			if (ft_strlen(tmp->command) > 0)
				ft_expand_cmd_and_args(tmp, env);
			else
				i = count_args(tmp->args);
			if (i > 0)
			{
				ft_strlcpy(tmp->command, tmp->args->next->value, \
						ft_strlen(tmp->args->next->value) + 1);
				tmp->args->next = tmp->args->next->next;
				ft_expand_cmd_and_args(tmp, env);
			}
		}
		ft_expansion_redir(tmp->redirections, env);
	}
}
