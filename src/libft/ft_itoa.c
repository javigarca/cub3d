/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:53:18 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/13 11:32:16 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_itoa()
 * 
 * DESCRIPTION:
 * 		Allocate with malloc(3) and return the string that represents the 
 * 		number given as argument. NULL si allocation fails. 
 * 
 * RETURN:
 *		The string representing the number.
 *
 * PARAMS:
 * 		@param n: number to represent as string.
 * 
 * TIPS:
 * 		1. - MINIMUM NEGATIVE VALUE!
 * 		2. - From the end to the begining.
 */

static char	*ft_convert(int n);
static char	*ft_max_negative(void);
static int	ft_count(int n);

char	*ft_itoa(int n)
{
	char	*out;

	if (n == -2147483648)
		out = ft_max_negative();
	else
	{
		out = ft_convert(n);
	}
	return (out);
}

static int	ft_count(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i = 2;
	}
	while (n > 9)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static char	*ft_max_negative(void)
{
	char	*out;

	out = (char *)malloc (11 + 1);
	if (out == NULL)
		return (NULL);
	ft_strlcpy(out, "-2147483648", 12);
	return (out);
}

static char	*ft_convert(int n)
{
	char	*out;
	int		i;

	i = ft_count(n);
	out = (char *)malloc((i + 1) * sizeof(char));
	if (out != NULL)
	{
		out[i] = '\0';
		if (n < 0)
		{
			n = -n;
			out[0] = '-';
		}
		while (n > 9)
		{
			out[i - 1] = 48 + (n % 10);
			n = n / 10;
			i--;
		}
		out[i - 1] = 48 + n;
	}
	return (out);
}
