/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:52:53 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/13 11:32:15 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_isalpha()
 * 
 * DESCRIPTION:
 * 		Check for a alphabetic character. No locale is considered.
 * 
 * RETURN:
 * 		Return nonzero if character is alphabetic and zero if not.
 * 
 * PARAM:
 * 		@param c: char to be check.
 * TIPS:
 * 		1. - Use ft_islower and ft_isupper
 */
static int	ft_islower(int c);
static int	ft_isupper(int c);

int	ft_isalpha(int c)
{
	if (ft_islower(c) || ft_isupper(c))
		return (1024);
	return (0);
}

static int	ft_islower(int c)
{
	if (c >= 97 && c <= 122)
		return (TRUE);
	return (FALSE);
}

static int	ft_isupper(int c)
{
	if (c >= 65 && c <= 90)
		return (TRUE);
	return (FALSE);
}
