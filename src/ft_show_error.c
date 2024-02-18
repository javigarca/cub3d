/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:27:35 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/18 14:23:55 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_show_error(const char *error_text)
{
	printf(KRED"Error\n");
	printf(KWHT"CUBE3D:");
	printf("%s \n", error_text);
	return (FALSE);
}
