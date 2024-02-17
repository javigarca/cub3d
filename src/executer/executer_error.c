/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:40:11 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 16:53:46 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	ft_exec_error(char *command, char *command_arg, char *output, int error)
{
	int	out;

	out = error;
	ft_colorirze(2, KRED);
	ft_putstr_fd("minishell: ", 2);
	ft_colorirze(2, KNRM);
	ft_putstr_fd(command, 2);
	if (ft_strlen(command_arg) > 0)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(command_arg, 2);
	}
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(output, 2);
	ft_putstr_fd("\n", 2);
	return (out);
}
