/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:55:43 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/20 16:08:36 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "map.h"
# include "get_next_line.h"
# include "parser.h"

int		ft_is_valid_input_file(char *arguments[]);
void	ft_show_logo(void);
void	ft_print(t_data data);
#endif