/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:43:51 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/13 11:32:27 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_strlen()
 * 
 * DESCRIPTION:
 * 		Compute the length of the string.
 * 
 * PARAMS:
 * 		@param s: string to be computed.
 * 
 * RETURN:
 * 		Number of characters that precede the NUL termination.
 * 
 * TIPS:
 * 		1. - *s++ !!
 */

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}
