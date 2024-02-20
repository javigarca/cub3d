/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_closed_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:59:11 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/19 13:38:12 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "parser.h"
#include "game_struct.h"

typedef struct {
    int row;
    int col;
} t_pos;

static t_pos ft_go_up(char **map2, int row, int col);
static t_pos ft_go_left(char **map2, int row, int col);
static t_pos ft_go_down(char **map2, int row, int col);
static t_pos ft_go_right(char **map2, int row, int col);

int ft_check_closed_map(t_data *game)
{
	int row;
	int col;
	t_pos pos;

	row = 7; //cambiar por posicion del player
	col = 4; //cambiar por posicon del player
	col = ft_strlen(game->map2d[row]) - 1;
	printf("EMPEZAMOS EN %d %d con valor %c \n", row, col, game->map2d[row][col]);
	pos = ft_go_up(game->map2d, row, col);
	printf("Se puede ir arriba hasta [%d][%d] \n", pos.row, pos.col);
	
    if (pos.row == -1)
	{
		return (FALSE);
	}
        
	pos = ft_go_left(game->map2d, pos.row, pos.col);
	printf("Se puede ir izquierda hasta [%d][%d] \n", pos.row, pos.col);
    if (pos.row == -1)
	{
		return (FALSE);
	}
        
	pos = ft_go_down(game->map2d, pos.row, pos.col);
	printf("Se puede ir abajo hasta [%d][%d] \n", pos.row, pos.col);
    if (pos.row == -1)
	{
		return (FALSE);
	}
	pos = ft_go_right(game->map2d, pos.row, pos.col);
	printf("Se puede ir derecha hasta [%d][%d] \n", pos.row, pos.col);
	if (pos.row == -1)
        return (FALSE);
    pos = ft_go_up(game->map2d, 8, 24);
	printf("Se puede ir arriba hasta [%d][%d] \n", pos.row, pos.col);
    
    if (pos.row < 0)
    {
        return (FALSE);
    }
    printf("\nSALIDA\n");
        
	return (TRUE);
}
static t_pos ft_go_up(char **map2, int row, int col)
{
	t_pos pos;

	pos.row = row;
	pos.col = col;

	while ( pos.row >0)
	{
		if (map2[ pos.row-1][ pos.col] == '1')
		{
			 pos.row--;
		}
		else if (map2[ pos.row][ pos.col-1] == '1')
		{
			 pos.col --;
		}		
		else if (map2[ pos.row-1][ pos.col-1] == '1')
		{
			pos.col--;
			pos.row--;
		}
		else if (map2[ pos.row][ pos.col+1] == '1')
		{
			 pos.col ++;
		}		
		else
		{
			pos.row = -1;
		    pos.row = -1;
			return (pos);
		}
			
	}
	return( pos);
}


static t_pos ft_go_left(char **map2, int row, int col)
{
	t_pos pos;

	pos.row = row;
	pos.col = col;

	while ( pos.col >0)
	{
		if (map2[pos.row][pos.col - 1] == '1')
		{
			 pos.col--;
		}
		else if (pos.row > 0 && map2[pos.row+1][ pos.col] == '1')
		{
			 pos.row --;
		}		
		else if (map2[ pos.row+1][ pos.col-1] == '1')
		{
			pos.col--;
			pos.row++;
		}
		else if (pos.row >0 && map2[ pos.row-1][ pos.col-1] == '1' )
		{
			pos.col--;
			pos.row--;
		}
		else if (pos.row >0 && map2[ pos.row-1][ pos.col] == '1')
		{
			 pos.row --;
		}		
		else
		{
			pos.row = -1;
		    pos.col = -1;
			return (pos);
		}
			
	}
	return (pos);
}
static t_pos ft_go_down(char **map2, int row, int col)
 {
    t_pos pos;
	
	pos.row = row;
	pos.col = col;

    
    while (pos.row > -1 && pos.row < 8) { // Use less-error-prone condition based on map bounds

        if (map2[pos.row + 1][pos.col] == '1') { // Move down
            pos.row++;
           
        } else if (map2[pos.row][pos.col - 1] == '1') { // Move left
            pos.col--;
           
        } else if (map2[pos.row + 1][pos.col - 1] == '1') { // Move down-left diagonal
            pos.col--;
            pos.row++;
           
        } else if (map2[pos.row + 1][pos.col + 1] == '1') { // Move down-right diagonal
            pos.col++;
            pos.row++;
           
        } else if (map2[pos.row][pos.col + 1] == '1') { // Move right
            pos.col++;
           
        } else {
            pos.row = -1;
            pos.col = -1;
            return pos;
        }
    }

    
    return pos;
}
static t_pos ft_go_right(char **map2, int row, int col) {
    t_pos pos;
	
	pos.row = row;
	pos.col = col;
	int length;
	int max = 8;
	length = ft_strlen(map2[pos.row]);
    
    while (pos.col > -1 && pos.col < length - 1)
	{ 
		length = ft_strlen(map2[pos.row]);

        if (map2[pos.row][pos.col + 1] == '1' ) { // Move right
            pos.col++;
            
        } else if (map2[pos.row - 1][pos.col + 1] == '1') { // Move up-right diagonal
            pos.col++;
            pos.row--;
        } else if (pos.row < max && map2[pos.row + 1][pos.col + 1] == '1') { // Move down-right diagonal
            pos.col++;
            pos.row++;
        } else if (map2[pos.row - 1][pos.col] == '1') { // Move up
            pos.row--;

        } else if (pos.row < max && map2[pos.row + 1][pos.col] == '1') { // Move down
            pos.row++;
        }
         else
		 {
            // No valid path found in any direction
            pos.row = -1;
            pos.col = -1;
            return pos;
        }
    }
    return pos;
}
