/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:22:26 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/13 11:02:06 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_memcmp()
 * 
 * DESCRIPTION:
 * 		Compares s1 against s2. both strings assumed to be n bytes long.
 * 
 * PARAM:
 * 		@param s1: string to be compared
 * 		@param s2: string to be compared
 * 
 * RETURN:
 * 		Return zero if two strings are identical, otherwise returns difference
 * 		between (treated as unsigned char values)
 */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				count;
	const unsigned char	*s1_aux;
	const unsigned char	*s2_aux;

	s1_aux = (const unsigned char *)s1;
	s2_aux = (const unsigned char *)s2;
	count = 0;
	while (count < n)
	{
		if (s1_aux[count] != s2_aux[count])
			return (s1_aux[count] - s2_aux[count]);
		count++;
	}
	return (0);
}
