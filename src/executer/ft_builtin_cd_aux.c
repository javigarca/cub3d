/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_cd_aux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:27:55 by xamayuel          #+#    #+#             */
/*   Updated: 2022/05/31 16:31:38 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

void	format_pwd(t_env *lst)
{
	char	cwd[MAXPROMPT];
	char	*new_pwd;

	unset("PWD", lst);
	getcwd(cwd, MAXPROMPT);
	new_pwd = (char *)malloc(MAXPROMPT);
	ft_strlcpy(new_pwd, "PWD=", MAXPROMPT);
	ft_strlcat(new_pwd, cwd, MAXPROMPT);
	update_export(new_pwd, lst);
	free(new_pwd);
}

/**
 * @brief FUnction to change enviroment vble PWD with new value
 * 
 * @param new_pwd New PWD to be set
 * @param lst Enviroment list
 */
void	ft_changepwd(char *new_pwd, t_env *lst)
{
	char	*old_pwd;
	char	*copy_pwd;

	old_pwd = (char *)malloc(MAXPROMPT);
	ft_strlcpy(old_pwd, "OLDPWD=", MAXPROMPT);
	ft_strlcat(old_pwd, ft_getenv("PWD", lst), MAXPROMPT);
	update_export(old_pwd, lst);
	free(old_pwd);
	copy_pwd = (char *)malloc(MAXPROMPT);
	ft_strlcpy(copy_pwd, "PWD=", MAXPROMPT);
	ft_strlcat(copy_pwd, new_pwd, MAXPROMPT);
	update_export(copy_pwd, lst);
	free(copy_pwd);
}
