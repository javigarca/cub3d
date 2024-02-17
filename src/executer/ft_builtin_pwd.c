/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_pwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:56:18 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 16:53:46 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	pwd(int fd)
{
	char	cwd[MAXPROMPT];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		ft_putstr_fd(cwd, fd);
		ft_putchar_fd('\n', fd);
		return (0);
	}
	else
	{
		ft_colorirze(2, KRED);
		perror("minishell: ");
		ft_colorirze(2, KNRM);
		return (1);
	}
}
