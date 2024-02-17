/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_replace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:31:15 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 17:29:46 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/**
 * Replaces specified characters in a string with a replacement character,
 * excluding those within quotes.
 * 
 * @param s1      The original string to be processed.
 * @param find    The characters to be replaced.
 * @param replace The replacement character.
 * @return        A new string with specified characters replaced,
 * 				  excluding those within quotes.
 */
char	*ft_replace(const char *s1, char *find, char replace)
{
	size_t	i;
	char	*dest;

	dest = (char *)malloc(ft_strlen(s1) + 1);
	if (dest != NULL)
	{
		i = 0;
		while (s1[i] != '\0')
		{
			if (ft_strchr(find, s1[i]) != NULL && \
				ft_open_quotes((char *)s1, i) == FALSE)
			{
				dest[i] = replace;
			}
			else
				dest[i] = s1[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}
