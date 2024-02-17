/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:57:18 by javigarc          #+#    #+#             */
/*   Updated: 2024/02/14 18:31:49 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include <sys/wait.h>
#include <errno.h>

#define STDIN_FILENO 0
#define STDOUT_FILENO 1

void	report_directory_error(char *cmd)
{
	if (ft_strchr(cmd, '.'))
	{
		ft_exec_error(cmd, "", "is a directory", 126);
		ft_error_w(126, 0);
	}
	else
	{
		if (ft_strchrc(cmd, '/') == 1)
			ft_exec_error(cmd, "", "No such file or directory", 127);
		else
			ft_exec_error(cmd, "", "command not found", 127);
		ft_error_w(127, 0);
	}
}

void	report_permission_error(char *cmd)
{
	ft_exec_error(cmd, "", "Permission denied", 126);
	ft_error_w(126, 0);
}

void	report_command_not_found(char *cmd)
{
	ft_exec_error(cmd, "", "command not found", 127);
	ft_error_w(127, 0);
}

void	report_no_such_file_or_dir(char *cmd)
{
	if ((cmd[0] == '/') || ((cmd[0] == '.') && (cmd[1] == '/')))
		ft_exec_error(cmd, "", "No such file or directory", 127);
	else
		ft_exec_error(cmd, "", "command not found", 127);
	ft_error_w(127, 0);
}
