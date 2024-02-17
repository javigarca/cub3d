/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:40:12 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/13 11:32:09 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_toupper()
 * 
 * DESCRIPTION:
 * 		Converts a lowercase letter to corresponding uppercase. No locale
 * 
 * RETURN:
 * 		Return the corresponding uppercase character.
 * 
 * PARAMS:
 * 		@param c: char to be convert.
 * 
 * TIPS:
 * 		1. - USE ft_islower
 * 		2. - Man ascii
 */
static int	ft_islower(int c);

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 32);
	return (c);
}

static int	ft_islower(int c)
{
	if (c >= 97 && c <= 122)
		return (TRUE);
	return (FALSE);
}
