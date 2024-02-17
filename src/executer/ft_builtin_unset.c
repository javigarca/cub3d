/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_unset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:30:39 by xamayuel          #+#    #+#             */
/*   Updated: 2022/05/31 17:10:36 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static int	next_step( t_env *anterior, t_env *actual, char *vble);

/**
 * @brief Function to unset a list of variables from t_env list
 * 
 * @param argv arguments with variables to unset
 * @param lst list with variables
 */
int	ft_unset(char **argv, t_env *lst)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		unset(argv[i], lst);
		i++;
	}
	return (0);
}

/**
 * @brief Function to unset 1 vble from list
 * 
 * @param vble Variable to be unset
 * @param lst list with variables
 */
void	unset(char *vble, t_env *lst)
{
	t_env	*anterior;
	t_env	*actual;

	actual = lst;
	anterior = NULL;
	while (actual != NULL)
	{
		if (next_step(anterior, actual, vble) == 1)
			break ;
		actual = actual->next;
		if (anterior == NULL)
			anterior = lst;
		else
			anterior = anterior->next;
	}
}

static int	next_step( t_env *anterior, t_env *actual, char *vble)
{
	if (ft_strncmp(actual->line, vble, ft_strlen(vble)) == 0 \
															&& anterior == NULL)
	{
		free(actual->line);
		actual->line = ft_strdup("");
		actual = actual->next;
		return (1);
	}
	if (ft_strncmp(actual->line, vble, ft_strlen(vble)) == 0 \
														&& actual->next == NULL)
	{
		anterior->next = NULL;
		free(actual->line);
		free(actual);
		return (1);
	}
	if (ft_strncmp(actual->line, vble, ft_strlen(vble)) == 0)
	{
		anterior->next = actual->next;
		free(actual->line);
		free(actual);
		actual = anterior->next;
		return (1);
	}
	return (0);
}
