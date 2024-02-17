/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:55:53 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/13 10:34:06 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_bzero()
 * 
 * DESCRIPTION:
 * 		Writes n zeroed bytes to the string s. If n is zero, does nothing.
 * 
 * PARAMETERS:
 * 		@param s: pointer to the string
 * 		@param n: number of bytes to be zeroed
 * 
 * RETURN:
 * 		VOID.
 * 
 * COMMENTS:
 * 		TIP: s[] is equal to (s)[]
 */

void	ft_bzero(void *s, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		((unsigned char *)s)[count] = 0;
		count ++;
	}
}
