/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 20:54:11 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/16 16:41:10 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include <sys/wait.h>
#include <errno.h>

static int	job_execution(t_commands *tmp, t_minishell *shell);
int			return_fds(t_cmd *cmd, int *fd_out, int *fd_int);
void		run_builtin(t_cmd *cmd, t_minishell *shell, int fdout, int exit);

/**
 * DESCRIPTION: function to execute the command list (; &&; ||)
 * 
 * @param lst 
 */
void	ft_execution(t_commands *lst, t_minishell *shell)
{
	t_commands	*tmp;
	int			job_status;

	job_status = 0;
	if (lst)
	{
		tmp = lst;
		while (tmp != NULL)
		{
			job_status = job_execution(tmp, shell);
			tmp = tmp->next;
		}
	}
	(void)job_status;
	shell->in_execution = 0;
}

/**
 * DESCRIPTION: function to execute pipe taking into account the number of pipes
 * 
 * @param tmp: point to command
 * @param shell : point tho shell paramater
 */

static int	job_execution(t_commands *tmp, t_minishell *shell)
{
	int		count_pipes;

	count_pipes = 0;
	ft_error_w(0, 1);
	count_pipes = pipes_count(tmp->pipes);
	if (count_pipes == 1)
		cmd_job(tmp->pipes->cmd, shell);
	if (count_pipes == 2)
	{
		two_pipes(tmp->pipes, shell);
		if (ft_error_r(1) > ft_error_r(0))
			ft_error_w(ft_error_r(1), 0);
	}
	if (count_pipes >= 3)
	{
		ft_plus_pipes(tmp->pipes, shell, 0);
		if (ft_error_r(1) > ft_error_r(0))
			ft_error_w(ft_error_r(1), 0);
	}
	return (0);
}
/*
aqui he cambiado para test_files
*/

void	child_cmd_job(t_cmd *cmd, char **new_argv, char **new_env, int fd[2])
{
	if (ft_strlen(new_argv[0]) == 0)
		exit(0);
	if (cmd->is_builtin == FALSE)
		execute_command(new_argv, new_env, fd);
	else
		exit(0);
}

void	cmd_job(t_cmd *cmd, t_minishell *shell)
{
	char	**new_env;
	char	**new_argv;
	int		fd[2];

	new_env = create_env_list(*shell);
	new_argv = create_argument_list(cmd);
	if (return_fds(cmd, &fd[0], &fd[1]) == 0)
	{
		g_signal = fork();
		if (g_signal == 0)
			child_cmd_job(cmd, new_argv, new_env, fd);
		wait(&g_signal);
		status_error(g_signal);
		if (cmd->is_builtin == TRUE && ft_strlen(cmd->command) > 0)
			run_builtin(cmd, shell, fd[1], FALSE);
	}
	else
		ft_error_w(1, 0);
	if (fd[0] > 2)
		close(fd[0]);
	if (fd[1] > 1)
		close(fd[1]);
	ft_2d_array_free(new_argv);
	ft_2d_array_free(new_env);
}

void	mini_cmd_job(t_cmd *cmd, t_minishell *shell)
{
	char	**new_argv;
	int		fdin;
	int		fdout;

	new_argv = create_argument_list(cmd);
	ft_error_w(return_fds(cmd, &fdin, &fdout), 1);
	if (ft_strlen(new_argv[0]) == 0)
		exit(0);
	if (cmd->is_builtin == FALSE)
	{
		dup2(fdin, STDIN_FILENO);
		dup2(fdout, STDOUT_FILENO);
		if (execve(new_argv[0], new_argv, create_argument_list(cmd)) == -1)
			msg_ft_exec_error(new_argv[0]);
	}
	if (cmd->is_builtin == TRUE && ft_strlen(cmd->command) > 0)
		run_builtin(cmd, shell, fdout, TRUE);
	if (fdout > 2)
		close(fdout);
	if (fdin > 1)
		close(fdin);
	ft_2d_array_free(new_argv);
}
