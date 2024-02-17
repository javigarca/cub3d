/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:55:51 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/10 13:04:50 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_substr()
 * 
 * DESCRIPTION:
 * 		Memory allocation with malloc (3) to return a fresh string based in 
 * 		string s.
 * 		The new string starts from 'start' and a maximum length of 'len'
 * 
 * PARAM:
 * 		@param     s: original string.
 * 		@param start: start point from original string.
 * 		@param   len: maximum length of the new string.
 * 
 * RETURN:
 * 		 The new string. Returns NULL if the memory allocation fails.
 * 
 */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*out;
	size_t	i;

	if (s == NULL)
		return (0);
	len_s = ft_strlen(s);
	if (start + len > len_s && start < len_s)
		len = len_s - start;
	if (start > len_s)
		len = 0;
	out = (char *)malloc(len + 1);
	if (out == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (i < len)
		{
			out[i] = s[start + i];
			i++;
		}
		out[i] = '\0';
		return (out);
	}
}
