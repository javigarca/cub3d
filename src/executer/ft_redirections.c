/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:27:57 by javigarc          #+#    #+#             */
/*   Updated: 2022/06/01 20:43:09 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include <sys/wait.h>
#include <errno.h>

int	open_great(t_redirections	*lst, int *fd_out)
{
	if (open(lst->filename, O_CREAT | O_RDWR, 0644) != -1)
		*fd_out = open(lst->filename, O_CREAT | O_RDWR, 0644);
	else
	{
		ft_exec_error((char *)(ft_strrchr(lst->filename, '/') + 1), \
													"", "Permission denied", 1);
		ft_error_w(1, 1);
		return (1);
	}
	return (0);
}

int	open_double_great(t_redirections	*lst, int *fd_out)
{
	if (open(lst->filename, O_CREAT | O_APPEND | O_RDWR, 0644) != -1)
		*fd_out = open(lst->filename, O_CREAT | O_APPEND | O_RDWR, 0644);
	else
	{
		ft_exec_error((char *)(ft_strrchr(lst->filename, '/') + 1), \
													"", "Permission denied", 1);
		ft_error_w(1, 1);
		return (1);
	}
	return (0);
}

int	open_less(t_redirections *lst, int *fd_in)
{
	if (open(lst->filename, O_CREAT | O_APPEND | O_RDWR, 0644) != -1)
		*fd_in = open(lst->filename, O_RDWR, 0644);
	else
	{
		ft_exec_error((char *)(ft_strrchr(lst->filename, '/') + 1), \
													"", "Permission denied", 1);
		ft_error_w(1, 1);
		return (1);
	}
	return (0);
}

int	return_fds(t_cmd *cmd, int *fd_in, int *fd_out)
{
	t_redirections	*lst;

	*fd_in = 0;
	*fd_out = 1;
	lst = cmd->redirections;
	while (lst)
	{
		if (lst->redirection_index > 0)
		{
			if (lst->redirection_index > 1 && *fd_out != 1)
				close(*fd_out);
			if (lst->type == RE_GREAT)
				if (open_great(lst, fd_out) == 1)
					return (1);
			if (lst->type == RE_DOUBLE_GREAT)
				if (open_double_great(lst, fd_out) == 1)
					return (1);
			if (lst->type == RE_LESS)
				if (open_less(lst, fd_in) == 1)
					return (1);
		}
		lst = lst->next;
	}
	return (0);
}
