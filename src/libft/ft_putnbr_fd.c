/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:57:12 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/13 11:32:24 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_putnbr_fd()
 * 
 * DESCRIPTION:
 * 		Output the integer n to the file descriptor fd.
 * 
 * RETURN:
 * 		NOTHING
 * 
 * PARAMS:
 * 		@param  n: number to be written.
 * 		@param fd: file descriptor.
 * 
 * TIPS:
 * 		1. Be careful with MIN_INT
 * 		2. Convert negative values to positive ones.
 */
static void	ft_putnbr_positive(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0 && n != -2147483648)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		ft_putnbr_positive(n, fd);
	}
}

static void	ft_putnbr_positive(int n, int fd)
{
	int		i;
	char	out[11];

	i = 0;
	while (n > 9)
	{
		out[i] = 48 + (n % 10);
		n = n / 10;
		i++;
	}
	out[i] = 48 + n;
	while (i >= 0)
	{
		ft_putchar_fd(out[i], fd);
		i--;
	}
}
