/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:57:18 by javigarc          #+#    #+#             */
/*   Updated: 2024/02/15 12:09:32 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include <sys/wait.h>
#include <errno.h>

#define STDIN_FILENO 0
#define STDOUT_FILENO 1

int	simple_comp(int a, int b);

void	execute_command(char **new_argv, char **new_env, int fd[2])
{
	int	lencomp;
	int	lenpwd;

	lenpwd = ft_strlen(getcwd(NULL, MAXPROMPT));
	lencomp = simple_comp(ft_strlen(new_argv[0]), lenpwd);
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	if ((ft_strncmp(new_argv[0], getcwd(NULL, MAXPROMPT), \
					ft_strlen(getcwd(NULL, MAXPROMPT))) == 0) && lencomp)
	{
		if ((lencomp == 1) || ((lencomp == 2) && (new_argv[0][lenpwd] == '/')))
		{
			ft_exec_error(new_argv[0], "", "is a directory", 126);
			ft_error_w(126, 0);
		}
	}
	else
	{
		if (execve(new_argv[0], new_argv, new_env) == -1)
			handle_exec_failure(new_argv);
	}
	exit(ft_error_r(0));
}

void	handle_exec_failure(char **new_argv)
{
	struct stat	statbuf;

	if (stat(new_argv[0], &statbuf) == 0)
	{
		if (S_ISDIR(statbuf.st_mode))
			report_directory_error(new_argv[0]);
		else if (access(new_argv[0], X_OK) != 0 && new_argv[0][0] == '.')
			report_permission_error(new_argv[0]);
		else
			report_command_not_found(new_argv[0]);
	}
	else
	{
		if (errno == ENOENT)
			report_no_such_file_or_dir(new_argv[0]);
		else
			report_command_not_found(new_argv[0]);
	}
}

int	simple_comp(int a, int b)
{
	if (a == b)
		return (1);
	if (a == (b +1))
		return (2);
	return (0);
}
