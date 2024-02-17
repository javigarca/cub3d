/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipes_plus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:39:21 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/14 19:41:18 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static void	child(t_pipes *pipcell, int fd[2], int *fdd)
{
	close(fd[0]);
	close(0);
	dup(*fdd);
	close(*fdd);
	if (pipcell->next)
	{
		close(1);
		dup(fd[1]);
		close(fd[1]);
	}
}

int	plus_pipes_plus(t_pipes *my_pipe, t_minishell *shell, int fdd)
{
	int		fd[2];
	int		g_pid;

	fd[0] = -1;
	fd[1] = -1;
	if (pipe(fd))
		return (-1);
	g_pid = fork();
	if (g_pid < 0)
	{
		close(fd[0]);
		close(fd[1]);
		close(fdd);
		return (-1);
	}
	else if (!g_pid)
	{
		child(my_pipe, fd, &fdd);
		mini_cmd_job(my_pipe->cmd, shell);
		_exit(0);
	}
	wait(&g_pid);
	close(fdd);
	close(fd[1]);
	return (fd[0]);
}
