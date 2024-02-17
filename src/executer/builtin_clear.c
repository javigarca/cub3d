/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:53:01 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/15 16:53:46 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
/**
 * Show at promt the starting messagge.
 * 
 * REFERENCE: 
 * https://stackoverflow.com/
 * questions/17271576/clear-screen-in-c-and-c-on-unix-based-system
 */
void	ft_clear_screen(void)
{
	ft_colorirze(2, "\x1b[H\x1b[J");
}
