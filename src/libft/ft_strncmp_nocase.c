/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_nocase.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:05:56 by xamayuel          #+#    #+#             */
/*   Updated: 2022/05/30 12:31:23 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_strncmp_nocase()
 * 
 * DESCRIPTION:
 * 		Lexicographically compare s1 and s2 NO CASE SENSITIVE.
 * 		Compares not more than n characters.
 * 		Characters after '\0' are not compared. Using unsigned char comparasion.
 * 
 * RETURN:
 * 		Return integer greater, equal, or less than 0, according as the string
 * 		s1 is greater than, equal to, or less than s2.
 * 
 * PARAMS:
 * 		@param s1: string to be compared.
 * 		@param s2: string to be compared.
 * 		@param  n: maximum number of chars to be compared.
 * 
 * TIPS:
 * 		1. - use unsigned char
 * 		2. - return when =\0 or !=
 * 		3. - If n=0 --> return 0
 */

int	ft_strncmp_nocase(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (s1[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (ft_tolower((unsigned char)s1[i]) != \
			ft_tolower((unsigned char)s2[i]))
			return (ft_tolower((unsigned char)s1[i]) - \
					ft_tolower((unsigned char)s2[i]));
		i++;
	}
	return (0);
}
