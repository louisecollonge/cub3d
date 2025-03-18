/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:23:19 by lcollong          #+#    #+#             */
/*   Updated: 2025/03/18 17:26:27 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h" //sur conseil de Baptiste : MLX42 et non minilibX
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <math.h>
# include <X11/X.h>

# define GREY "\033[90m"
# define BOLDRED "\033[1;31m"
# define BLUE "\033[34m"
# define GREEN "\033[32m"
# define YELLOW "\033[38;2;255;165;0m"
# define RED "\033[31m"
# define RESET "\033[0m"

# define BUFFER_SIZE 1 //gnl

typedef enum	s_option
{
	FLOOR,
	CEILING,
	NO,
	SO,
	WE,
	EA,
} t_option;

typedef struct s_data
{
	char			*floor;
	char			*ceiling;
	int				floor_rgb;
	int				ceiling_rgb;
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*we;
	mlx_texture_t	*ea;
	int				fd_map;
	int				character_nb;
	char			*line;
	char			*map_string;
	char			**map_tab;
	int				in_map;
}	t_data;

typedef struct s_player
{
	float	x; //float pour la precision apres la virgule
	float	y;
	float	dir;
}	t_player;

typedef struct s_game
{
	mlx_t			*mlx; //pointeur instance MLX42
	mlx_image_t		*img; //image affichee par render
	t_player		player;
	mlx_texture_t	**textures; // tableau de textures
	char			**map; //carte du jeu en 2D
}	t_game;

// Parsing
t_data	*parse_args(int ac, char **av);
t_data	*parse_file(char *file);
void	parse_texture(char *line, t_data *data, t_option option, int *count);
void	parse_color(char *line, t_data *data, t_option, int *count);
void	parse_map_line(t_data *data, int *count);
bool	wall_outline(t_data *data);
bool	empty_space(t_data *data);

// Parsing utils
bool	is_orientation(char *line);
bool	acceptable_char(char c);
bool	space(char **tab, size_t x, size_t y);
bool	zero(char **tab, size_t x, size_t y);
bool	end_of_map(t_data *data);

// Init
void	init_game();

// Rendering

// Input

// Textures

// Utils
void	error(char *s, t_data *data, void *p1, void *p2);
void	cleanup(t_data *data);
size_t	tab_line_nb(char **tab);
void	print_tab(char **tab); //debug


// Get Next Line
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*add_buff(char *big, char *small);
char	*ft_strchr(const char *s, int c);
char	*read_file(char	*str, int fd);
char	*ft_get_line(char *str);
char	*get_next_line(int fd);
char	*remain(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);


#endif
