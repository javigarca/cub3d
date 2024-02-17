/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_intdollar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:59:51 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/13 20:04:31 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expanser.h"

char	*ft_expand_quotes_dollar(char *input, t_env *env)
{
	char	*new_line;

	new_line = (char *)malloc(MAXPROMPT);
	ft_bzero(new_line, MAXPROMPT);
	ft_exp_dollar_m(new_line, input, env, 0);
	free(input);
	return (new_line);
}

/**
 * @brief 
 * 
 * @param input 
 * @return char* 
 */
char	*ft_expand_dollar(char *input, t_env *env)
{
	char	*txt_env;
	char	*txt_out;
	int		i;

	i = 0;
	txt_out = NULL;
	while (input[i] != '\0')
	{
		if (input[i] == '\'' || input[i] == '\"')
			break ;
		i++;
	}
	txt_env = ft_substr(input, 0, i);
	if (ft_getenv(txt_env, env) != NULL)
	{
		txt_out = (char *) malloc (ft_strlen(ft_getenv(txt_env, env)) + 1);
		ft_strlcpy(txt_out, ft_getenv(txt_env, env), \
		ft_strlen(ft_getenv(txt_env, env)) + 1);
	}
	else
	{
		txt_out = NULL;
	}
	free(txt_env);
	return (txt_out);
}
