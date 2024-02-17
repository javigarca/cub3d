/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:30:39 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 16:53:46 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static void	print_env_line(char *line, int fd);

/**
 * @brief Function to show vbl list
 * 
 * @param argn Number of arguments
 * @param argv Arguments
 * @param lst  list of variables
 */
int	ft_env(int argn, char *argv[], t_env *lst, int fd)
{
	t_env	*tmp;

	tmp = lst;
	(void)argv;
	if (argn == 1)
	{
		while (tmp != NULL)
		{
			if (ft_strlen(tmp->line) > 0)
				if (ft_strncmp(tmp->line, "OLDPWD", 6) != 0)
					print_env_line(tmp->line, fd);
			tmp = tmp->next;
		}
	}
	else if (argn > 1)
	{
		ft_exec_error("env", "", "No such file or directory", 127);
		return (127);
	}
	return (0);
}

/**
 * @brief Function to format env line
 * 
 * @param line Line to be formatted.
 */
static void	print_env_line(char *line, int fd)
{
	int	i;

	i = 0;
	ft_colorirze(fd, KGRN);
	if (ft_strchr(line, '=') != NULL)
	{
		while (line[i] != '\0')
		{
			ft_putchar_fd(line[i++], fd);
			if (line[i] == '=')
			{
				ft_colorirze(fd, KNRM);
			}
		}
		ft_putchar_fd('\n', fd);
	}
}
