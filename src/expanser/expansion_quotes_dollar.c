/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_quotes_dollar.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:19:47 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/14 20:02:47 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expanser.h"

int		ft_ft_max_env_arg_size(t_env *env);
char	*ft_expand_dollar(char *input, t_env *env);

static void	process_output(char *copy, char *output, char *error, t_env *lst)
{
	if (ft_strncmp(copy, "?", 1) == 0)
		ft_strlcpy(output, error, MAXPROMPT);
	else if (ft_strlen(copy) == 1)
		ft_strlcpy(output, "$", MAXPROMPT);
	else
		ft_strlcpy(output, ft_getenv(copy, lst), MAXPROMPT);
	if (ft_strlen(copy) > 1 && ft_strncmp(copy, "?", 1) == 0)
		ft_strlcat(output, copy + 1, MAXPROMPT);
}

static void	ft_free_memory(char *copy, char *error, char *line)
{
	free(copy);
	free(error);
	free(line);
}

static char	*ft_extraer_dollar(char *line, t_env *lst, int *length)
{
	int		i;
	char	*copy;
	char	*output;
	char	*error;

	error = ft_itoa(ft_error_r(0));
	i = 1;
	copy = (char *)malloc (ft_strlen(line) + 1);
	ft_strlcpy(copy, (char *)line + 1, ft_strlen(line)+1);
	while (copy[i] != '\0' && copy[i] != '$' && copy[i] != '\"' && \
			copy[i] != '\'' && copy[i] != '|' && copy[i] != ',' \
			&& copy[i] != ']' && copy[i] != '@' && copy[i] != '?' \
			&& copy[i] != ' ' && copy[i] != '.' && copy[i] != '/')
		i++;
	copy[i] = '\0';
	*length = ft_strlen(copy);
	output = (char *)malloc (MAXPROMPT);
	ft_bzero(output, MAXPROMPT);
	process_output(copy, output, error, lst);
	ft_free_memory(copy, error, line);
	return (output);
}

int	ft_ext_int_dollar(char *str, char *new_line, t_env *env)
{
	int		length;
	char	*dollar;
	char	*vble;

	length = 0;
	dollar = (char *) malloc(MAXPROMPT);
	ft_strlcpy(dollar, str, MAXPROMPT);
	vble = ft_extraer_dollar(dollar, env, &length);
	ft_strlcat(new_line, vble, MAXPROMPT);
	free(vble);
	return (length);
}

void	ft_exp_dollar_m(char *new_line, char *input, t_env *env, int i)
{
	int		open_d_quotes;
	int		open_s_quotes;

	open_d_quotes = 1;
	open_s_quotes = 1;
	while (input[i] != '\0')
	{
		if (input[i] == '$' && open_s_quotes == 1 && (input[i +1] != ' ' && \
			input[i + 1] != '\n' && input[i + 1] != 0))
		{
			i = i + 1 + ft_ext_int_dollar((char *)(input + i), new_line, env);
			continue ;
		}
		if (input[i] == '\"' && open_s_quotes == 1)
		{
			i = i + ft_change_quote(&open_d_quotes);
			continue ;
		}
		if (input[i] == '\'' && open_d_quotes == 1)
		{
			i = i + ft_change_quote(&open_s_quotes);
			continue ;
		}
		ft_charlcat(new_line, input[i++], MAXPROMPT);
	}
}
