/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:56:01 by xamayuel          #+#    #+#             */
/*   Updated: 2022/05/28 13:22:38 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expanser.h"

void	ft_filename_expand(char *str, t_redirections	*lst);

/**
 * @brief 
 * 
 * @param lst 
 * @param env 
 * @param last 
 */
void	ft_expansion_redir(t_redirections *lst, t_env *env)
{
	t_redirections	*tmp;

	if (lst)
	{
		tmp = lst;
		while (tmp)
		{
			if (tmp->redirection_index > 0)
			{
				tmp->filename = ft_expand_quotes_dollar(tmp->filename, env);
				if (tmp->type == RE_DOUBLE_LESS)
				{
					tmp->filename = ft_expand_heredoc(tmp->filename);
					tmp->type = RE_LESS;
				}
				if (ft_strncmp(tmp->filename, "/", 1) != 0)
					ft_filename_expand(ft_getenv("PWD", env), tmp);
			}
			tmp = tmp->next;
		}
	}
}

/**
 * @brief 
 * 
 * @param path 
 * @param lst 
 */
void	ft_filename_expand(char *path, t_redirections	*lst)
{
	size_t	path_size;
	size_t	file_size;
	size_t	total_size;
	char	*total_path;

	path_size = ft_strlen(path);
	file_size = ft_strlen(lst->filename);
	total_size = path_size + file_size + 2;
	total_path = ft_calloc(total_size, sizeof(char));
	ft_strlcpy(total_path, path, total_size);
	ft_strlcat(total_path, "/", total_size);
	ft_strlcat(total_path, lst->filename, total_size);
	free(lst->filename);
	lst->filename = ft_strdup(total_path);
	free(total_path);
}
