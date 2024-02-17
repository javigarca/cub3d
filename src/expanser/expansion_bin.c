/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_bin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:41:43 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/12 20:54:14 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expanser.h"
#include <sys/stat.h>

static void	ft_ex_cmd_b_1(t_cmd *cmd, t_env *env, int *exists, char ***paths);
static void	ft_ex_cmd_b_2(t_cmd *cmd, int exec_exists, char **paths);

void	ft_expansion_cmd_bin(t_cmd *cmd, t_env *env)
{
	char	**paths;
	int		exec_exists;

	paths = NULL;
	ft_ex_cmd_b_1(cmd, env, &exec_exists, &paths);
	if (exec_exists == FALSE && paths != NULL)
		ft_ex_cmd_b_2(cmd, exec_exists, paths);
	if (paths != NULL && exec_exists == TRUE)
		ft_2d_array_free(paths);
}

static void	ft_ex_cmd_b_1(t_cmd *cmd, t_env *env, int *exec_exists, \
							char ***paths)
{
	char	*env_path;

	*exec_exists = FALSE;
	if (!(ft_strncmp(cmd->command, "", 1)) || (cmd->command[0] == '/'))
		return ;
	*exec_exists = ft_exec_is_builtin(cmd);
	if (*exec_exists == FALSE)
		*exec_exists = ft_exec_file_exists(ft_getenv("PWD", env), cmd);
	if (*exec_exists == FALSE)
		*exec_exists = ft_exec_file_exists("", cmd);
	if (*exec_exists == FALSE)
	{
		env_path = ft_getenv("PATH", env);
		*paths = ft_split(env_path, ':');
	}
}

static void	ft_ex_cmd_b_2(t_cmd *cmd, int exec_exists, char **paths)
{
	int	i;

	i = 0;
	if (exec_exists == FALSE && paths)
	{
		while (paths[i] != NULL)
		{
			exec_exists = ft_exec_file_exists(paths[i], cmd);
			if (exec_exists == TRUE)
				break ;
			i++;
		}
		ft_2d_array_free(paths);
	}
}
