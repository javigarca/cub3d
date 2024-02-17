/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_bin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:41:43 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/12 20:51:53 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expanser.h"
#include <sys/stat.h>

int	ft_exec_is_builtin(t_cmd *lst)
{
	char	**builts;
	int		i;
	int		resultado;

	resultado = FALSE;
	i = 0;
	builts = ft_buitls();
	while (i < 7)
	{
		if (ft_strncmp(builts[i], lst->command, ft_strlen(builts[i])) == 0)
		{
			lst->is_builtin = TRUE;
			resultado = TRUE;
		}
		i++;
	}
	i = 0;
	while (i < 7)
	{
		free(builts[i]);
		i++;
	}
	free(builts);
	return (resultado);
}

/**
 * @brief 
 * 
 * @param file 
 * @return int 
 */
int	ft_file_is_executable(char *file)
{
	if (access(file, F_OK | X_OK) == 0)
	{
		return (TRUE);
	}
	return (FALSE);
}

/**
 * @brief 
 * 
 * @param path 
 * @param cmd 
 * @return int 
 */
int	ft_exec_file_exists(char *path, t_cmd *cmd)
{
	size_t	path_size;
	size_t	file_size;
	size_t	total_size;
	char	*total_path;
	int		is_exec;

	is_exec = FALSE;
	path_size = ft_strlen(path);
	file_size = ft_strlen(cmd->command);
	total_size = path_size + file_size + 2;
	total_path = ft_calloc(total_size, sizeof(char));
	ft_strlcpy(total_path, path, total_size);
	ft_strlcat(total_path, "/", total_size);
	ft_strlcat(total_path, cmd->command, total_size);
	is_exec = ft_file_is_executable(total_path);
	if (is_exec == TRUE)
	{
		free(cmd->command);
		cmd->command = ft_strdup(total_path);
	}
	free(total_path);
	return (is_exec);
}

char	**ft_buitls(void)
{
	char	**builts;

	builts = (char **)malloc(7 * sizeof(char *));
	builts[0] = ft_strdup("echo");
	builts[1] = ft_strdup("export");
	builts[2] = ft_strdup("cd");
	builts[3] = ft_strdup("pwd");
	builts[4] = ft_strdup("unset");
	builts[5] = ft_strdup("env");
	builts[6] = ft_strdup("exit");
	return (builts);
}
