/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:40:12 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/13 11:32:31 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_tolower()
 * 
 * DESCRIPTION:
 * 		Converts a upperrcase letter to corresponding lowercase. No locale
 * 
 * RETURN:
 * 		Return the corresponding lowercase character.
 * 
 * PARAMS:
 * 		@param c: char to be convert.
 * 
 * TIPS:
 * 		1. - USE ft_isupper
 * 		2. - Man ascii
 */
static int	ft_isupper(int c);

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c + 32);
	return (c);
}

static int	ft_isupper(int c)
{
	if (c >= 65 && c <= 90)
		return (TRUE);
	return (FALSE);
}
