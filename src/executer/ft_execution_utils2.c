/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:36:39 by javigarc          #+#    #+#             */
/*   Updated: 2024/02/14 12:24:55 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include <sys/wait.h>
#include <errno.h>

void	cmd_not_found_err(char *new_arg)
{
	printf("%s\n", new_arg);
	ft_exec_error(new_arg, "", "command not found2", 127);
	ft_error_w(127, 0);
	exit(-1);
}

int	args_count(t_args *tmp)
{
	int	count;

	count = 1;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

void	exit_error(char **new_argv)
{
	ft_error_w(ft_exit(new_argv), 0);
	ft_2d_array_free(new_argv);
	exit(ft_error_r(0));
}

void	status_error(int child_status)
{
	if (child_status == 512)
		ft_error_w(2, 0);
	else
		if (child_status == 32256)
			ft_error_w(126, 0);
	else
		if (child_status != 0 && child_status != 126)
			ft_error_w(127, 0);
}

/**
 * DESCRIPTION: function to count the number of pipes
 * 
 * @param lst pointer to pipes list
 */
int	pipes_count(t_pipes *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count ++;
		lst = lst->next;
	}
	return (count);
}
