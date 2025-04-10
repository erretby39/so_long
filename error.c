/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soer-ret <soer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:02:36 by soer-ret          #+#    #+#             */
/*   Updated: 2025/04/10 09:57:22 by soer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

void	ft_err(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	exit(1);
}

void	ft_error(char *err_msg, char *tmp, t_track *game)
{
	if (game->map != NULL)
		ft_free(game->map);
	free(tmp);
	ft_err(err_msg);
	exit(1);
}

int	close_window(t_game *game)
{
	ft_free(game->track.map);
	mlx_destroy_window(game->mlx_in, game->mlx_window);
	free_text(game);
	mlx_destroy_display(game->mlx_in);
	free(game->mlx_in);
	exit(0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}
