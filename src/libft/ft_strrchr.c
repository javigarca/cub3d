/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:54:32 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/13 11:32:30 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_strchr()
 * 
 * DESCRIPTION:
 * 		Locates the last occurrence of c(converted to a char) in the string s.
 * 		The terminating null character is considered part of string.
 * 
 * PARAMS:
 * 		@param s: string.
 * 		@param c: char to locate last occurrence.
 * 
 * RETURN:
 * 		Return a pointer to the located character o NULL if does not appear.
 * 
 * TIPS:
 * 		1. - \0 is a character, so ft_strlen + 1
 */

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;
	size_t	i;
	char	*aux;

	aux = NULL;
	s_len = ft_strlen(s);
	i = 0;
	while (i < s_len + 1)
	{
		if ((char)c == s[i])
			aux = ((char *)s + i);
		i++;
	}
	return (aux);
}
