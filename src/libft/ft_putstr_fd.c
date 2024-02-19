/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:48:15 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/19 12:17:57 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_putstr_c()
 * 
 * DESCRIPTION:
 * 		Writes the string in the file defined by the file descriptor
 * 
 * PARAMS:
 * 		@param  s: string to be written.
 * 		@param fd: file descriptor.
 * 
 * RETURN:
 * 		Nothing.
 */

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}
