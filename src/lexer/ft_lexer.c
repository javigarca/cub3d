/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:18:37 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 17:19:43 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static t_token	*ft_create_first_token(void);
static void		ft_populate_token_list(t_token *lst, char *line);
static void		ft_special_tokens(t_token *lst, char *line);

/**
 * Lexically analyzes the input line and generates a linked list of tokens.
 * 
 * @param line Input line to be analyzed.
 * @return     Pointer to the head of the token list.
 */
t_token	*ft_lexer(char *line)
{
	t_token	*token_lst;

	token_lst = NULL;
	token_lst = ft_create_first_token();
	ft_populate_token_list(token_lst, line);
	ft_sort_token(token_lst);
	return (token_lst);
}

/**
 * Creates the first token in the token list with default values.
 * 
 * @return Pointer to the first token.
 */
static t_token	*ft_create_first_token(void)
{
	t_token	*lst;

	lst = (t_token *)malloc(sizeof(t_token));
	lst->index = 0;
	lst->value = ft_strdup("NONE");
	lst->type = NONE;
	lst->next = NULL;
	return (lst);
}

/**
 * Populates the token list by parsing the input line
 * and adding tokens accordingly.
 * 
 * @param lst  Pointer to the head of the token list.
 * @param line Input line to be parsed.
 */
static void	ft_populate_token_list(t_token *lst, char *line)
{
	char	*line_new;
	char	**words;
	int		position;
	int		i;

	if (line)
	{
		i = 0;
		position = 0;
		ft_special_tokens(lst, line);
		line_new = ft_replace(line, "|><; &()", 7);
		words = ft_split(line_new, 7);
		while (words[i])
		{
			position += ft_strlen((char *)(line + position)) - \
			ft_strlen(ft_strnstr((char *)(line + position), words[i], \
			ft_strlen((char *)(line + position)))) + ft_strlen(words[i]);
			ft_add_token(lst, WORD, words[i], position + 0);
			i++;
		}
		i = 0;
		ft_2d_array_free(words);
		free(line_new);
	}
}

/**
 * Identifies and adds special tokens (e.g., parentheses, operators)
 * to the token list.
 * 
 * @param lst  Pointer to the head of the token list.
 * @param line Input line to be analyzed.
 */
static void	ft_special_tokens(t_token *lst, char *line)
{
	int	i;

	if (line)
	{
		i = ft_do_tokens(lst, line);
		ft_add_token(lst, LINE_END, "endline", i + 1);
	}
}

/**
 * Adds a new token to the token list with the specified type, value, and index.
 * 
 * @param lst   Pointer to the head of the token list.
 * @param type  Type of the token.
 * @param value Value of the token.
 * @param index Index of the token in the input line.
 */
void	ft_add_token(t_token *lst, t_token_type type, char *value, int index)
{
	t_token	*tmp;

	tmp = lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = (t_token *)malloc(sizeof(t_token));
	tmp->next->index = index;
	tmp->next->value = ft_strdup(value);
	tmp->next->type = type;
	tmp->next->next = NULL;
}
