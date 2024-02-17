/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:57:57 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/18 20:17:04 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_strtrim()
 * 
 * DESCRIPTION:
 * 		Removes from the string s1 the chars of the string set allocated at
 * 		the beggining and end of the string.
 * 
 * PARAM:
 * 		@param  s1: original string.
 * 		@param set: start point from original string.
 * 
 * RETURN:
 * 		 The new string. Returns NULL if the memory allocation fails.
 * 
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*out;
	size_t	left;
	size_t	right;
	size_t	i;

	if (s1 == NULL || set == NULL)
		return (0);
	i = 0;
	while (ft_strchr(set, s1[i]) != NULL && i < ft_strlen(s1))
		i++;
	left = i;
	i = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) != NULL && i > left)
		i--;
	right = i;
	if ((left == ft_strlen(s1)) || (ft_strlen(s1) == 0))
		out = ft_strdup("");
	else
	{
		out = (char *)malloc((right - left + 1) + 1);
		if (out != NULL)
			ft_strlcpy(out, s1 + left, right - left +2);
	}
	return (out);
}
