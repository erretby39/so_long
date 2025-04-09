/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soer-ret <soer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:21:46 by soer-ret          #+#    #+#             */
/*   Updated: 2025/04/09 20:42:01 by soer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    mv_counter(void)
{
    static int i;
    
    i++;
    ft_printf("move %d\n", i);
}

void    move_left(t_game *game, int i, int j)
{
    if (game->track.map[i][j] == '1' || (game->track.map[i][j] == 'E' \
        && game->track.c_count != game->track.c_collected))
        return ;
    if (game->track.map[i][j] == 'E' \
        && game->track.c_count == game->track.c_collected)
    {
        mv_counter();
		ft_putst("you win ;)\n");
		close_window(game);
    }
	else if (game->track.map[i][j] == 'C')
		game->track.c_collected++;
    game->track.map[i][j] = 'P';    
	game->track.map[game->track.x][game->track.y] = '0';
	game->track.y--;
    mv_counter();
	creat_map(game);
}

void    move_right(t_game *game, int i, int j)
{
    if (game->track.map[i][j] == '1' || (game->track.map[i][j] == 'E' \
        && game->track.c_count != game->track.c_collected))
        return ;
    if (game->track.map[i][j] == 'E' \
        && game->track.c_count == game->track.c_collected)
    {
        mv_counter();
		ft_putst("you win ;)\n");
		close_window(game);
    }
	else if (game->track.map[i][j] == 'C')
		game->track.c_collected++;
    game->track.map[i][j] = 'P';    
	game->track.map[game->track.x][game->track.y] = '0';
	game->track.y++;
    mv_counter();
	creat_map(game);
}

void    move_down(t_game *game, int i, int j)
{
    if (game->track.map[i][j] == '1' || (game->track.map[i][j] == 'E' \
        && game->track.c_count != game->track.c_collected))
        return ;
    if (game->track.map[i][j] == 'E' \
        && game->track.c_count == game->track.c_collected)
    {
        mv_counter();
		ft_putst("you win ;)\n");
		close_window(game);
    }
	else if (game->track.map[i][j] == 'C')
		game->track.c_collected++;
    game->track.map[i][j] = 'P';    
	game->track.map[game->track.x][game->track.y] = '0';
	game->track.x++;
    mv_counter();
	creat_map(game);
}

void    move_up(t_game *game, int i, int j)
{
    if (game->track.map[i][j] == '1' || (game->track.map[i][j] == 'E' \
        && game->track.c_count != game->track.c_collected))
        return ;
    if (game->track.map[i][j] == 'E' \
        && game->track.c_count == game->track.c_collected)
    {
        mv_counter();
		ft_putst("you win ;)\n");
		close_window(game);
    }
	else if (game->track.map[i][j] == 'C')
		game->track.c_collected++;
    game->track.map[i][j] = 'P';    
	game->track.map[game->track.x][game->track.y] = '0';
	game->track.x--;
    mv_counter();
	creat_map(game);
}