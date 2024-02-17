/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charlcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:00:54 by xamayuel          #+#    #+#             */
/*   Updated: 2022/06/01 15:02:17 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_charlcat(char *str, char char_new, size_t size)
{
	char	aux[2];

	aux[1] = '\0';
	aux[0] = char_new;
	return (ft_strlcat(str, aux, size));
}
