/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:51:31 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 17:23:05 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	ft_return_open_double(int open_double, int open_single);
static int	ft_return_open_single(int open_double, int open_single);

/**
 * Checks if there are open quotes (single or double) in the given line 
 * up to the specified length.
 * 
 * @param line Input line to check for open quotes.
 * @param len  Length of the line to be checked.
 * @return     Total count of open quotes found in the line.
 */
int	ft_open_quotes(char *line, int len)
{
	int	open_single;
	int	open_double;
	int	i;

	open_double = FALSE;
	open_single = FALSE;
	i = 0;
	while (line[i] && i < len)
	{
		if (line[i] == 34)
			open_double = ft_return_open_double(open_double, open_single);
		if (line[i] == 39)
			open_single = ft_return_open_single(open_double, open_single);
		i++;
	}
	return (open_double + open_single);
}

/**
 * Returns the state of open double quotes based on the current states of
 * open single and double quotes.
 * 
 * @param open_double Current state of open double quotes.
 * @param open_single Current state of open single quotes.
 * @return            Updated state of open double quotes.
 */
static int	ft_return_open_double(int open_double, int open_single)
{
	if ((open_double == FALSE) && (open_single == FALSE))
		return (TRUE);
	else if ((open_double == TRUE) && (open_single == FALSE))
		return (FALSE);
	return (open_double);
}

/**
 * Returns the state of open single quotes based on the current states
 * of open single and double quotes.
 * 
 * @param open_double Current state of open double quotes.
 * @param open_single Current state of open single quotes.
 * @return            Updated state of open single quotes.
 */
static int	ft_return_open_single(int open_double, int open_single)
{
	if ((open_single == FALSE) && (open_double == FALSE))
		return (TRUE);
	else if ((open_single == TRUE) && (open_double == FALSE))
		return (FALSE);
	return (open_single);
}

/**
 * Counts the number of backslash characters ('\') in the given line
 * up to the specified length.
 * 
 * @param line Input line to count backslashes.
 * @param len  Length of the line to be checked.
 * @return     Total count of backslashes found in the line.
 */
int	ft_count_backslash(const char *line, int len)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (line[i] && i < len)
	{
		if (line[i] == 92)
			count++;
		i++;
	}
	return (count);
}
