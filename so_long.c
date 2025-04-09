/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soer-ret <soer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:55:32 by soer-ret          #+#    #+#             */
/*   Updated: 2025/04/09 18:24:13 by soer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    moves_key(int key, t_game *game)
{
    if (key == 'w')
        move_up(game, game->track.x - 1, game->track.y);
    else if (key == 's')
        move_down(game, game->track.x + 1, game->track.y);
    else if (key == 'a')
        move_left(game, game->track.x, game->track.y - 1);
    else if (key == 'd')
        move_right(game, game->track.x, game->track.y + 1);
    else if (key == 65307)
        close_window(game);
    return (1);
}

void creat_map2(t_game *game, int i, int j, int flag)
{
    if (flag == 2)
        mlx_put_image_to_window(game->mlx_in, game->mlx_window,\
        game->texture.coin_img, j * 64, i * 64);
    else if (flag == 1)
        mlx_put_image_to_window(game->mlx_in, game->mlx_window,\
        game->texture.wall_img, j * 64, i * 64);
    else if (flag == 0)
        mlx_put_image_to_window(game->mlx_in, game->mlx_window,\
        game->texture.floor_img, j * 64, i * 64);
}
void    creat_map(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->track.map[i])
    {
        j = 0;
        while (game->track.map[i][j])
        {
            if(game->track.map[i][j] == 'P')
                mlx_put_image_to_window(game->mlx_in, game->mlx_window,\
                     game->texture.player_img, j * 64, i * 64);
            else if(game->track.map[i][j] == 'E')
                mlx_put_image_to_window(game->mlx_in, game->mlx_window,\
                 game->texture.exit_img, j * 64, i * 64);
            else if(game->track.map[i][j] == 'C')
                creat_map2(game, i, j, 2);
            else if(game->track.map[i][j] == '1')
                    creat_map2(game, i, j, 1);
            else if(game->track.map[i][j] == '0')
                creat_map2(game, i, j, 0);
            j++;
        }
        i++;
    }
}

void    so_long(t_game *game)
{
    if (ft_strlen(game->track.map[0]) > 30 || ver_ln(game->track.map) > 16)
    {
        ft_free(game->track.map);
        ft_err("too big 'try other map'");
    }
    game->track.c_collected = 0;
    game->mlx_in = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx_in, \
        ft_strlen(game->track.map[0]) * 64, \
        ver_ln(game->track.map) * 64, "So_long");
    set_texture(game);
    creat_map(game);
    mlx_key_hook(game->mlx_window, &moves_key, game);
    mlx_hook(game->mlx_window, DestroyNotify, 0, &close_window, game);
    mlx_loop(game->mlx_in);

}

int main(int ac, char **av)
{
    char *buff;
    t_game game;
    
    buff = NULL;
    if (ac != 2)
        ft_err("u need 2 arg\n");
    argchek(av[1]);
    map_parsing(av, buff, &game, 0);
   so_long(&game);
}
