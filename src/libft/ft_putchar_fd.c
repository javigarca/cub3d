/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:45:07 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/13 11:06:26 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_putchar_fd()
 * 
 * DESCRIPTION:
 * 		Writes the charcter 'c' in the file defined by the file descriptor fd
 * 
 * PARAMS:
 * 		@param  c: char to be writen.
 * 		@param fd: file descriptor.
 * 
 * RETURN:
 *		Nothing.
 * 
 */

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
