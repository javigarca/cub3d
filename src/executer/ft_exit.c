/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:11:50 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/14 19:24:12 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static int	ft_only0(char *argv);
static int	ft_isvalid(char *str);
// FALTA HACER FREE ARGV ENV??

int	ft_exit(char **argv)
{
	if (ft_isvalid(argv[1]) == FALSE)
		return (ft_exec_error("exit", "", "numeric argument required", 255));
	if (ft_2d_array_size(argv) > 2 && ft_isvalid(argv[1]) == TRUE)
		return (ft_exec_error("", "", "too many arguments", 1));
	else if (argv[1] != NULL && ft_only0(argv[1]) == TRUE)
		return (0);
	else if (ft_2d_array_size(argv) > 2 && ft_isvalid(argv[1]) == FALSE)
		return (ft_exec_error("", argv[1], "numeric argument required", 255));
	else if (argv[1] != NULL)
		return (ft_atoi(argv[1]));
	else
		return (ft_exec_error("exit", argv[1], " se requiere", 2));
	return (0);
}

static int	ft_isvalid(char *str)
{
	int	out;
	int	i;

	out = TRUE;
	i = 0;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			out = FALSE;
			break ;
		}
		i++;
	}
	return (out);
}

static int	ft_only0(char *argv)
{
	int	i;

	i = 1;
	if (argv[0] != '0' && argv[0] != '+' && argv[0] != '-')
		return (FALSE);
	while (argv[i] != '\0')
	{
		if (argv[i] != '0')
		{
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}
