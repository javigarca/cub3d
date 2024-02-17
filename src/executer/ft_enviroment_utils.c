/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enviroment_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:16:00 by xamayuel          #+#    #+#             */
/*   Updated: 2022/05/31 17:13:12 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

char	**ft_enviroment_copy(char **original)
{
	int		count;
	int		i;
	char	**copy;

	i = 0;
	count = ft_2d_array_size(original);
	copy = (char **)malloc((count + 1) * sizeof(char *));
	while (i < count)
	{
		copy[i] = ft_strdup(original[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	add_env_last(t_env *lst, char *line)
{
	t_env	*tmp;

	tmp = lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = (t_env *)malloc(sizeof(t_env));
	tmp->next->line = ft_strdup(line);
	tmp->next->next = NULL;
}

char	*ft_env_var(char *line)
{
	int		i;
	char	*var;

	i = 0;
	while (line[i] != '\0' && line[i] != '=')
		i++;
	var = ft_calloc(i + 1, sizeof(char));
	ft_strlcpy(var, line, i + 1);
	return (var);
}

void	del_elem_env(t_env *lst, char *line)
{
	t_env	*tmp;
	char	*var;

	tmp = lst;
	var = ft_env_var(line);
	while (tmp != NULL)
	{
		if (ft_strncmp(ft_env_var(tmp->line), var, ft_strlen(var)) == 0)
		{
			free(tmp->line);
			tmp->line = ft_calloc(ft_strlen(line), sizeof(char));
			ft_strlcpy(tmp->line, line, ft_strlen(line) + 1);
			return ;
		}
		tmp = tmp->next;
	}
	free(var);
}
