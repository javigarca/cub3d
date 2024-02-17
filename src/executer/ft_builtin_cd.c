/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:09:03 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 16:53:46 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static int	ft_cd_with_argument(t_env *tmp, char **argv);
static void	ft_cd_go_home(t_env *lst);
static char	*ft_generate_new_pwd(char **argv, t_env *lst);
/**
 * REFERENCES: 
 * 	https://www.ediciones-eni.com/open/mediabook.aspx?\
 * 			idR=064c3adc280f35b92a94ada11fb686a2
 *  https://linuxize.com/post/linux-cd-command/
 *  https://www.geeksforgeeks.org/cd-command-in-linux-with-examples/
 */

/**
 * @brief Function to change current directory
 * 
 * @param argn Number of arguments
 * @param argv List of argument
 * @param lst  Enviroment list
 */
int	ft_cd(int argn, char *argv[], t_env *lst)
{
	t_env	*tmp;
	int		output;

	output = 0;
	tmp = lst;
	if (argn == 2)
		output = ft_cd_with_argument(tmp, argv);
	else if (argn == 1)
		ft_cd_go_home(tmp);
	chdir(ft_getenv("PWD", lst));
	format_pwd(tmp);
	return (output);
}

static int	ft_cd_with_argument(t_env *tmp, char **argv)
{
	DIR		*dir;
	char	*new_pwd;
	int		output;

	output = 0;
	new_pwd = ft_generate_new_pwd(argv, tmp);
	dir = opendir(new_pwd);
	if (dir != NULL)
		ft_changepwd(new_pwd, tmp);
	else
	{
		ft_colorirze(2, KRED);
		ft_putstr_fd("minishell: ", 2);
		ft_colorirze(2, KNRM);
		perror("cd");
		output = 1;
	}
	free(dir);
	free(new_pwd);
	return (output);
}

static void	ft_cd_go_home(t_env *lst)
{
	char	*new_pwd;
	DIR		*dir;

	new_pwd = (char *)malloc(MAXPROMPT);
	if (ft_getenv("HOME", lst) != NULL)
		ft_strlcpy(new_pwd, ft_getenv("HOME", lst), MAXPROMPT);
	else
		ft_putstr_fd("HOME env. not set", 2);
	dir = opendir(new_pwd);
	if (dir != NULL)
		ft_changepwd(new_pwd, lst);
	else
		perror(KRED"minishell:"KNRM" cd");
	free(dir);
	free(new_pwd);
}

static char	*ft_generate_new_pwd(char **argv, t_env *lst)
{
	char	*new_pwd;

	if (argv[1][0] != '/' || argv[1][0] != '~')
	{
		new_pwd = (char *)malloc(MAXPROMPT);
		ft_strlcpy(new_pwd, ft_getenv("PWD", lst), MAXPROMPT);
		if (argv[1][ft_strlen(new_pwd)] != '/')
			ft_strlcat(new_pwd, "/", MAXPROMPT);
		ft_strlcat(new_pwd, argv[1], MAXPROMPT);
	}
	if (argv[1][0] == '~')
	{
		new_pwd = (char *)malloc(MAXPROMPT);
		ft_strlcpy(new_pwd, ft_getenv("HOME", lst), MAXPROMPT);
		ft_strlcat(new_pwd, (char *)(argv[1] + 1), MAXPROMPT);
	}
	if (argv[1][0] == '/')
		ft_strlcpy(new_pwd, argv[1], MAXPROMPT);
	return (new_pwd);
}
