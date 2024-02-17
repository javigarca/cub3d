/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:57:17 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/10 18:43:02 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

void	msg_ft_exec_error(char *argv)
{
	ft_exec_error(&argv[0], "", "command not found", 127);
	ft_error_w(127, 0);
	exit(-1);
}
