/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:54:05 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/10 13:07:24 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

char	**contar(t_cmd *cmd)
{
	int		count;
	t_args	*tmp;
	char	**argv;

	count = 1;
	tmp = cmd->args;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	argv = (char **)malloc((count + 1) * sizeof(char *));
	return (argv);
}

char	**create_argument_list(t_cmd *cmd)
{
	t_args	*tmp;
	int		i;
	char	**argv;

	argv = contar(cmd);
	if (cmd->command != NULL)
		argv[0] = ft_strdup(cmd->command);
	else
		argv[0] = ft_strdup("");
	tmp = cmd->args;
	i = 1;
	while (tmp)
	{
		if (tmp->arg_index > 0)
		{
			argv[i] = ft_strdup(tmp->value);
			i++;
		}
		tmp = tmp->next;
	}
	argv[i] = NULL;
	return (argv);
}

int	number_argument_list(char **argv)
{
	int	count;

	count = 0;
	while (argv[count] != NULL)
		count++;
	return (count);
}

char	**create_env_list(t_minishell shell)
{
	t_env	*tmp;
	char	**env;
	int		count;
	int		i;

	count = 0;
	tmp = shell.s_env->next;
	while (tmp)
	{
		count ++;
		tmp = tmp->next;
	}
	env = (char **)malloc((count + 1) * sizeof (char *));
	tmp = shell.s_env->next;
	i = 0;
	while (tmp)
	{
		env[i] = ft_strdup(tmp->line);
		i++;
		tmp = tmp->next;
	}
	env[i] = NULL;
	return (env);
}

void	ft_do_backups(int flag)
{
	static int	stdin;
	static int	stdou;
	static int	stderr;

	if (flag)
	{
		printf("flag");
		stdin = dup(STDIN_FILENO);
		stdou = dup(STDOUT_FILENO);
		stderr = dup(STDERR_FILENO);
	}
	else if (!flag)
	{
		printf("no flag");
		dup2(stdin, 0);
		dup2(stdou, 1);
		dup2(stderr, 2);
	}
}
