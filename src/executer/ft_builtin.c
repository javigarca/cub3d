/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:41:31 by javigarc          #+#    #+#             */
/*   Updated: 2024/02/10 15:03:12 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include <sys/wait.h>
#include <errno.h>

void	built_cont(char **new_argv, int fdout, t_cmd *cmd, t_minishell *shell)
{
	if (ft_strncmp(cmd->command, "export", ft_strlen(cmd->command)) == 0)
		ft_error_w(export(number_argument_list(new_argv), new_argv \
							, shell->s_env, fdout), 0);
	else if (ft_strncmp(cmd->command, "pwd", ft_strlen(cmd->command)) == 0)
		ft_error_w(pwd(fdout), 0);
	else if (ft_strncmp(cmd->command, "cd", ft_strlen(cmd->command)) == 0)
		ft_error_w(ft_cd(number_argument_list(new_argv), new_argv, \
									shell->s_env), 0);
	else if (ft_strncmp(cmd->command, "env", ft_strlen(cmd->command)) == 0)
		ft_error_w(ft_env(number_argument_list(new_argv), new_argv, \
								shell->s_env, fdout), 0);
	else if (ft_strncmp(cmd->command, "unset", ft_strlen(cmd->command)) == 0)
		ft_error_w(ft_unset(new_argv, shell->s_env), 0);
	else if (ft_strncmp(cmd->command, "echo", ft_strlen(cmd->command)) == 0)
		ft_error_w(ft_echo(number_argument_list(new_argv), \
									new_argv, fdout), 0);
	else if (ft_strncmp(cmd->command, "exit", ft_strlen(cmd->command)) == 0)
	{
		if (ft_2d_array_size(new_argv) == 1)
			ft_error_w(0, 0);
		else
			ft_error_w(ft_exit(new_argv), 0);
		ft_2d_array_free(new_argv);
		exit(ft_error_r(0));
	}
}

void	run_builtin(t_cmd *cmd, t_minishell *shell, int fdout, int exit_status)
{
	char	**new_argv;

	new_argv = create_argument_list(cmd);
	built_cont(new_argv, fdout, cmd, shell);
	ft_2d_array_free(new_argv);
	if (exit_status == TRUE)
		exit (0);
}
