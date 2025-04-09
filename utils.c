/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soer-ret <soer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:48:12 by soer-ret          #+#    #+#             */
/*   Updated: 2025/04/09 16:15:50 by soer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_putst(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        write (1, &str[i], 1);
        i++;
    }
}

void    close_window1(t_game *game)
{
    ft_free(game->track.map);
    mlx_destroy_window(game->mlx_in, game->mlx_window);
    mlx_destroy_display(game->mlx_in);
    free(game->mlx_in);
    exit (1);
}

void    set_texture(t_game *game)
{
    int height;
    int width;
    game->texture.player_img = mlx_xpm_file_to_image(game->mlx_in, \
    "./text/player.xpm", &height, &width);
    if (!game->texture.player_img)
        close_window1(game);
    game->texture.coin_img = mlx_xpm_file_to_image(game->mlx_in, \
    "./text/coin.xpm", &height, &width);
    if (!game->texture.coin_img)
        close_window1(game);
    game->texture.floor_img = mlx_xpm_file_to_image(game->mlx_in, \
    "./text/floor.xpm", &height, &width);
    if (!game->texture.floor_img)
        close_window1(game);
    game->texture.wall_img = mlx_xpm_file_to_image(game->mlx_in, \
    "./text/wall.xpm", &height, &width);
    if (!game->texture.wall_img)
        close_window1(game);
    game->texture.exit_img = mlx_xpm_file_to_image(game->mlx_in, \
    "./text/exit.xpm", &height, &width);
    if (!game->texture.exit_img)
        close_window1(game);
}

void free_text(t_game *game)
{
    mlx_destroy_image(game->mlx_in, game->texture.coin_img);
    mlx_destroy_image(game->mlx_in, game->texture.exit_img);
    mlx_destroy_image(game->mlx_in, game->texture.floor_img);
    mlx_destroy_image(game->mlx_in, game->texture.player_img);
    mlx_destroy_image(game->mlx_in, game->texture.wall_img);

}

int    ver_ln(char **str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}