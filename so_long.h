/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soer-ret <soer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:28:58 by soer-ret          #+#    #+#             */
/*   Updated: 2025/04/09 21:55:55 by soer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "printf/ft_printf.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_texture
{
	void		*player_img;
	void		*coin_img;
	void		*exit_img;
	void		*wall_img;
	void		*floor_img;
}				t_texture;

typedef struct s_tarck
{
	char		**map;
	int			c_valid;
	int			x;
	int			y;
	int			e_path;
	int			c_collected;
	int			c_count;
	int			p_count;
	int			e_count;
}				t_track;

typedef struct s_game
{
	void		*mlx_window;
	void		*mlx_in;
	int			line_length;
	t_texture	texture;
	t_track		track;
}				t_game;

void			so_long(t_game *game);
void			creat_map(t_game *game);
void			creat_map2(t_game *game, int i, int j, int flag);
int				moves_key(int key, t_game *game);
int				close_window(t_game *game);
void			set_texture(t_game *game);
void			free_text(t_game *game);
void			move_left(t_game *game, int i, int j);
void			move_right(t_game *game, int i, int j);
void			move_down(t_game *game, int i, int j);
void			move_up(t_game *game, int i, int j);
int				ver_ln(char **str);
void			mv_counter(void);
void			close_window1(t_game *game);

//map && parsing
void			argchek(char *str);
void			map_parsing(char **av, char *buff, t_game *game, int ver_line);
			//vertical_line
void			checkers(t_game *game, int ver_line, char *buff2);
void			map_edge(t_track *pos, int ver_line, char *buff2);
void			map_epc(t_track *pos, char *buff2);
void			map_check(t_track *pos, char *buff2);
void			p_pos(t_track *pos);
void			floodfill(int x, int y, char **map, t_track *game);
void			last_check(t_track *pos, char *buff2);

//assisted function
char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			ft_putst(char *str);

// error msg
void			ft_error(char *err_msg, char *tmp, t_track *game);
void			ft_err(char *str);
void			ft_free(char **tmp);

//get next line
char			*get_next_line(int fd);
char			*chyata(char *str);
char			*lineuntilnl(char *str);
char			*read_line(char *line, int fd);
char			*ft_strchr(const char *str, int c);
char			*ft_strjoin(char *s1, char *s2);
void			*ft_memcpy(void *dst, const void *src, size_t n);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#endif
