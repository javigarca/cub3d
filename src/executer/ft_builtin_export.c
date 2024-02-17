/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:30:39 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 16:53:46 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

void		update_export(char *argv, t_env *lst);
void		sort_env_list(t_env *lst);
static int	is_valid_vble(char *vble);
static void	printexportline(char *line, int fd);
static int	export_vble(char *vble, t_env *tmp);

/**
 * @brief Function to insert vble in vble list or show the list
 * 
 * @param argn Number of arguments
 * @param argv Arguments
 * @param lst  list of variables
 */
int	export(int argn, char *argv[], t_env *lst, int fd)
{
	int		i;
	t_env	*tmp;
	int		output;

	output = 0;
	i = 1;
	sort_env_list(lst);
	tmp = lst;
	if (argn == 1)
	{
		while (tmp != NULL)
		{
			if (ft_strlen(tmp->line) > 0)
				printexportline(tmp->line, fd);
			tmp = tmp->next;
		}
	}
	else if (argn > 1)
	{
		while (i < argn)
			output = export_vble(argv[i++], tmp);
	}
	return (output);
}

static void	printexportline(char *line, int fd)
{
	int	i;

	i = 0;
	ft_colorirze(fd, KYEL);
	ft_putstr_fd("declare -x ", fd);
	ft_colorirze(1, KGRN);
	while (line[i] != '=' && line[i] != '\0')
		ft_putchar_fd(line[i++], fd);
	if (line[i] == '=')
	{
		ft_colorirze(fd, KNRM);
		ft_putstr_fd("=\"", fd);
		ft_putstr_fd((char *)ft_strchr(line, '=') + 1, fd);
		ft_putstr_fd("\"", fd);
	}
	ft_putstr_fd("\n", fd);
}

static int	export_vble(char *vble, t_env *tmp)
{
	char	aux[MAXPROMPT];
	int		output;

	output = 0;
	if (is_valid_vble(vble) == TRUE)
		update_export(vble, tmp);
	else
	{
		ft_strlcpy(aux, "`", MAXPROMPT);
		ft_strlcat(aux, vble, MAXPROMPT);
		ft_strlcat(aux, "'", MAXPROMPT);
		output = ft_exec_error("export", aux, "not a valid identifier", 1);
	}
	return (output);
}

/**
 * @brief Function to update vble with new value
 * 
 * @param argn Number of arguments
 * @param argv Arguments
 * @param lst  list of variables
 */
void	update_export(char *argv, t_env *lst)
{
	char	*var;
	int		j;
	t_env	*tmp;

	j = 0;
	tmp = lst;
	while (argv[j] != '\0' && argv[j] != '=')
		j++;
	var = ft_calloc(j + 1, sizeof(char));
	ft_strlcpy(var, argv, j + 1);
	unset(var, tmp);
	add_env_last(tmp, argv);
	free(var);
	sort_env_list(lst);
}

static int	is_valid_vble(char *vble)
{
	int	i;

	i = 1;
	if (ft_isalpha(vble[0]) > 0 || vble[0] == '_')
	{
		while (vble[i] != '\0' && vble[i] != '=')
		{
			if (ft_isalpha(vble[i]) == 0)
				if (ft_isdigit(vble[i]) == 0 && vble[i] != '_')
					return (FALSE);
			i++;
		}
	}
	else
		return (FALSE);
	return (TRUE);
}
