/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:40:51 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/18 17:52:25 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_striteri()
 * 
 * DESCRIPTION:
 * 		Applies the function 'f' to each character of the string.
 * 
 * PARAMS:
 * 		@param s: string
 * 		@param f: function to be applied.
 * 
 * RETURN:
 * 		Nothing.
 * 
 * TIPS
 * 		1. Take care of & inside the fuction.
 */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (s && f)
	{
		i = 0;
		while (s[i] != '\0')
		{
			f(i, &s[i]);
			i++;
		}
	}
}
