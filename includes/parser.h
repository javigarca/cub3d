/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:53:41 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/19 16:11:09 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include "get_next_line.h"
# include "game_struct.h"

t_data *ft_parse_map(char *filename);
int ft_check_closed_map(t_data *game);
char *ft_parse_map_color(t_color *color, char *filename, char *type);
char *ft_parse_map_texture(char **texture, char *filename, char *direction);
void ft_parse_map_lines(char **map2d, char *filename);
int ft_count_map_lines(char *filename);
#endif