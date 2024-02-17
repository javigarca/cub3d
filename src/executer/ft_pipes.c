/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:34:32 by javigarc          #+#    #+#             */
/*   Updated: 2024/02/14 19:41:11 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static int	two_pipes_child(int fd1[2], t_cmd *cmd, t_minishell *shell);

#define READ_END    0    /* index pipe extremo escritura */
#define WRITE_END   1    /* index pipe extremo lectura */

void	second_child_process(int fd1[], t_pipes *my_pipe, t_minishell *shell)
{
	int	gpid;

	gpid = fork();
	if (gpid == 0)
	{
		dup2(fd1[READ_END], STDIN_FILENO);
		close(fd1[READ_END]);
		mini_cmd_job(my_pipe->next->cmd, shell);
	}
	else
		close(fd1[READ_END]);
}

int	two_pipes(t_pipes *my_pipe, t_minishell *shell)
{
	int	fd1[2];
	int	child_status;
	int	gpid;

	pipe(fd1);
	gpid = fork();
	if (gpid == 0)
		two_pipes_child(fd1, my_pipe->cmd, shell);
	else
	{
		close(fd1[WRITE_END]);
		if (!ft_error_r(1))
			second_child_process(fd1, my_pipe, shell);
	}
	wait(&child_status);
	wait(&child_status);
	if (WIFEXITED(child_status))
		ft_error_w(WEXITSTATUS(child_status), 0);
	return (0);
}

static int	two_pipes_child(int fd1[2], t_cmd *cmd, t_minishell *shell)
{
	close(fd1[READ_END]);
	dup2(fd1[WRITE_END], STDOUT_FILENO);
	close(fd1[WRITE_END]);
	if (!ft_error_r(1))
		mini_cmd_job(cmd, shell);
	return (0);
}

void	ft_plus_pipes(t_pipes *pipes, t_minishell *shell, int status)
{
	int	fdd;
	int	gpid;

	gpid = fork();
	if (gpid == 0)
	{
		fdd = dup(0);
		while (pipes->next != NULL)
		{
			fdd = plus_pipes_plus(pipes, shell, fdd);
			pipes = pipes->next;
		}
		dup2(fdd, STDIN_FILENO);
		close(fdd);
		mini_cmd_job(pipes->cmd, shell);
	}
	else
	{
		waitpid(gpid, &status, 0);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		else
			status = 1;
		ft_error_w(status, 0);
	}
}
